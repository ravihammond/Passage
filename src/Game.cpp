



#include <stdio.h>
#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>

#include "Game.h"
using namespace std;

//-------------------------------------------------------------------------------------//
//	GAME CONSTRUCTOR
//- Takes thread input, current game score, and current users best score.
//- Sets all global variables to their default values.
Game::Game(int *input,int *score,int *best){
	this->best = best;
	this->input=input;
	this->score=score;
	invincible=false;
	stop = 0;
	counter = 0;
	wallcounter = 0;
	scorecounter=0;
	dscore = 0.0;
	multiplier = 1;
	speed = 9000000;
	timeleft = 0.0;
	hasmult = false;
	multtimeleft = 0.0;
	shieldon = false;
	student = new Player(&shieldon,&invincible,&timeleft);
	shieldwall = false;
}

//-------------------------------------------------------------------------------------//
//	LOOP METHOD
//- Main game loop.
//- Contains game loop that increments by one, activates the game to refresh at milestone
void Game::loop(){
	while (stop != 1){

		counter++;
		if(counter == speed){
			counter = 0;
			wallcounter++;

			//incrementing score and reduce time between frames
			scorecounter++;
			if(scorecounter == 8){
				scorecounter = 0;
				dscore += multiplier;
				if(speed > 3900000)
					speed -= 5000;
			}

			//input from thread changes players direction
			if(*input == 'z' || *input == 'w' || *input == 65)
				student->moveUp();
			else if(*input == 'x' || *input == 's' || *input == 66)
				student->moveDown();
			student->stepTime();

			//chance to add powerups to right hand side of screen
			if(rand()%1000 == 0)
				obstacles.push_back(new Invincible(slope.getNum(),&invincible,&timeleft));
			if(rand()%650 == 0)
				obstacles.push_back(new Points(slope.getNum(),&dscore));
			if(rand()%550 == 0)
				obstacles.push_back(new Multiplier(slope.getNum(),&multiplier,&hasmult,&multtimeleft));
			if(rand()%8000 == 0)
				obstacles.push_back(new Shield(slope.getNum(),&shieldon));

			//every 50 refreshes add a random obstacle to right hand side of screen
			if(wallcounter==50){
				wallcounter = 0;
				obstrand = rand()%100;
				if(obstrand<15) 
					obstacles.push_back(new Gobstacle(slope.getNum(),&invincible,&shieldon));
				else if(obstrand>85) 
					obstacles.push_back(new Dobstacle(slope.getNum(),&invincible,&shieldon));
				else
					obstacles.push_back(new Obstacle(slope.getNum(),&invincible,&shieldon));
			}
			obstacles.push_back(new Trail(student->getHeight()));
			obstacles.push_back(new Border(slope.getNum(),&block,&shieldon,&shieldwall));
			slope.nextNum();

			//clears screen
			erase();

			//shuffling objects to the left and adds them to the screen
			block.shuffleAll();
			student->printToTerminal();
			for (int i = 0; i < obstacles.size(); ++i){
				obstacles[i]->stepLeft();
				obstacles[i]->printToTerminal();	
			}

			//displays current multiplier on screen
			*score = (int)dscore;
			if(hasmult){
				multtimeleft -= 0.03;
				if(multtimeleft<0){
					multtimeleft = 0;
				}
				attron(COLOR_PAIR(10));
				mvprintw(16,2,"Multiplier ");
				attroff(COLOR_PAIR(10));
				mvprintw(16,13,"x%.1f", multiplier);
				if(multtimeleft==0){
					hasmult = false;
					multiplier = 1;
				}
			}
			//displays timer until invincibily runs out
			if(invincible){
				timeleft -= 0.03;
				if(timeleft<0){
					timeleft = 0;
				}
				attron(COLOR_PAIR(8));
				mvprintw(17,2,"Invincible: ");
				attroff(COLOR_PAIR(8));
				mvprintw(17,14,"%.2f", timeleft);
				if(timeleft==0)
					invincible = false;
			}
			//adds current and best scores to bottem of screen
			attron(COLOR_PAIR(5));
			mvprintw(36,0," score: %d ",*score);
			mvprintw(36,88,"            ");
			mvprintw(36,88," best: %d",*best);
			attroff(COLOR_PAIR(5));
			curs_set(0);
			//prints everything that has been added to the screen
			refresh();

			//deletes obstacle if off screen to the left
			for (int i = 0; i < 10; ++i){
				if(obstacles[i]->isOffScreen()){
					Slider* obstacletemp = obstacles[i];
					obstacles.erase(obstacles.begin()+i);
					delete obstacletemp;
				}
			}

			//If player collides with an object on screen, perform that objects interact method.
			for (int i = 0; i < obstacles.size(); ++i){
				if(obstacles[i]->interact(student->getCoordinates(),student->getCoordSize())){
					input[1]=1;
					refresh();
					stop=1;
				}
			}

			//if shield was on when player hit a border, activate this statement
			if(shieldwall){
				invincible = true;
				timeleft += 2;
				student->moveToCenter();
				shieldwall = false;
				shieldon = false;
			}
		}
	}
}


//-------------------------------------------------------------------------------------//
//	GAME OVER METHOD
//- Prints the game over message.
//- returns true if user beat their previous highscore, else return false.
bool Game::gameOver(Highscorelist *highscores){
	mvprintw(18,46,"GAME OVER");
	mvprintw(19,46,"SCORE : %d ",*score);
	mvprintw(21,46,"press spacebar continue...",*score);
	refresh();
	if(highscores->isHigh(*score)){
		return true;		
	}else{
		return false;
	}
}

//-------------------------------------------------------------------------------------//
//	INITIALIZE BORDER METHOD
//- adds the starting 100 flat borders which can be seen at the start screen.
void Game::initialiseBorders(){
	obstacles.push_back(new Border(0,&block,&shieldon,&shieldwall));
	for (int i = 0; i < 100; ++i){
		for (int j = 0; j < obstacles.size(); ++j)
			obstacles[j]->stepLeft();
		obstacles.push_back(new Border(0,&block,&shieldon,&shieldwall));
	}
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Adds the first hundred borders to the screen that are seen at the menu.
void Game::printBorders(){
	for (int i = 0; i < 100; ++i){
		obstacles[i]->printToTerminal();
	}
}

//-------------------------------------------------------------------------------------//
//	ADD TITLE METHOD
//- Calls the addtitle method from the Textblock object.
void Game::addTitle(){
	block.addTitle();
}

//-------------------------------------------------------------------------------------//
//	RESET BEST METHOD
//- If the user is changed, reset their current best to 0.
void Game::resetBest(){
	*best = 0;
}

//empty destructor, because dragon.
Game::~Game(){
 //             ______________
 //       ,===:'.,            `-._
 //            `:.`---.__         `-._
 //              `:.     `--.         `.
 //                \.        `.         `.
 //        (,,(,    \.         `.   ____,-`.,
 //     (,'     `/   \.   ,--.___`.'
 // ,  ,'  ,--.  `,   \.;'         `
 //  `{D, {    \  :    \;
 //    V,,'    /  /    //
 //    j;;    /  ,' ,-//.    ,---.      ,
 //    \;'   /  ,' /  _  \  /  _  \   ,'/
 //          \   `'  / \  `'  / \  `.' /
 //           `.___,'   `.__,'   `.__,'  
}
