#include "Points.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
using namespace std;

//-------------------------------------------------------------------------------------//
//	POINTS CONSTRUCTOR
//- Randomly picks a start position for points.
//- Fills coordinate vector.
//- Takes gobal variable as parameters to communicate to game loop.
//- Sets points sprite.
Points::Points(int offset,double *score) : Powerup(offset){
	this->score = score;
	startposition = 7+offset+rand()%22;
	displayed = true;
	for(int i = 1; i <= 12; ++i){
		if(i<=4){
			if(i%2 != 0){
				coordinates.push_back(startposition+i/2);
			}else
				coordinates.push_back(100);
		}else if(i>=4 && i<=8){
			if(i%2 != 0){
				coordinates.push_back(startposition+i/2-2);
			}else
				coordinates.push_back(101);
		}else{
			if(i%2 != 0){
				coordinates.push_back(startposition+i/2-4);
			}else
				coordinates.push_back(102);
		}
	}
	sprite = 'O';

	//creates and fills seperate word array for the message after interaction.
	word = "+50";
	for(int i = 0; i < word.size()*2; ++i){
		if(i%2 == 0){
			wordcoordinates.push_back(startposition-2);
		}else{
			wordcoordinates.push_back(22+i/2);
		}
	}
}
//-------------------------------------------------------------------------------------//
//	INTERACT METHOD
//-	If passed in coordinates are equal to points,
//	add 50 points to score and hide points from display.
bool Points::interact(int* pcoords,int* pcoordsize){
	int y,x;
	for (int i = 0; i < (*pcoordsize)/2; ++i){
		y = *(pcoords+i*2);
		x = *(pcoords+i*2+1);
		for (int j = 0; j < coordinates.size()/2; ++j){
			if(y==coordinates[j*2] && x==coordinates[j*2+1]){
				if(displayed){
					*score += 50;
				}
				displayed = false;
				return false;
			}
		}
	}
	return false;
}

//-------------------------------------------------------------------------------------//
//	STEPLEFT METHOD
//- Moves obstacle y coordinates left 1 when called.
//- If displayed = false, move object up by 1 every 10 refreshes.
void Points::stepLeft(){
	for (int i = 0; i < coordinates.size(); i++){
		if(i%2 != 0)
			--coordinates[i];
	}
	if(!displayed){
		int counter;
		for (int i = 0; i < wordcoordinates.size(); i++){
			if(i%2 != 0){
				--wordcoordinates[i];
			}
		}
		counter++;
		if(counter==10){
			counter = 1;
			for (int i = 0; i < wordcoordinates.size(); i++){
				if(i%2 == 0){
					--wordcoordinates[i];
				}
			}
		}
	}
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Prints points to yellow in blue text
void Points::printToTerminal(){
	attron(COLOR_PAIR(7));
	if(displayed){
		for(int i = 0; i < 6; ++i){
			mvaddch(coordinates[i*2],coordinates[i*2+1],sprite);
		}
	}
	if(!displayed){
		for(int i = 0; i < word.size(); ++i){
			mvaddch(wordcoordinates[i*2],wordcoordinates[i*2+1],word.at(i));
		}
	}

	attroff(COLOR_PAIR(7));
}

//-------------------------------------------------------------------------------------//
//	OFFSCREEN METHOD
//- Loops through all coordinates, if all are < 0 set offscreen to false to delete object.
bool Points::isOffScreen(){
	bool offscreen = true;
	for (int i = 0; i < coordinates.size()/2; ++i){
		if (coordinates[i*2+1]>0)
			offscreen = false;
	}
	return offscreen;
}

//empty destructor, because dragon.
Points::~Points(){
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
