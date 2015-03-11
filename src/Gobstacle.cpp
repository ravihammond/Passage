#include "Gobstacle.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
using namespace std;

//-------------------------------------------------------------------------------------//
//	GOBSTACLE CONSTRUCTOR
//- Randomly picks a word to use, starting direction, starting position of dobstacle.
//- Takes invincible and shieldon bools to handle the powerup events.
Gobstacle::Gobstacle(int offset,bool *invincible,bool *shieldon) : Obstacle(offset,invincible,shieldon){
	this->shieldon=shieldon;
	this->invincible=invincible;
	this->offset = offset;
	wordarray[0] = "ASSIGNMENT";
	wordarray[1] = "EXTENSION";
	wordarray[2] = "TUTORIAL";
	wordarray[3] = "PRACTICAL";
	wordarray[4] = "WORKSHOP";
	wordarray[5] = "LECTURE";
	word = wordarray[rand()%6];
	startposition = rand()%24;
	for(int i = 1; i <= word.size()*2; ++i){
		if(i%2 != 0){
			coordinates.push_back((i/2+startposition)%24+offset+7);
		}else{
			coordinates.push_back(100);
		}
	counter = 0;
	if(rand()%2==1) direction = 1; 
	else direction = -1;
	}
	destroyed = false;
}

//-------------------------------------------------------------------------------------//
//	INTERACT METHOD
//-	If passed in coordinates are equal to obstacle return true, else false.
//- If shield is on hide obstacle and return false.
//- If Invincible is on return false.
bool Gobstacle::interact(int* pcoords,int* pcoordsize){
	if(!destroyed){
		int y,x;
		for (int i = 0; i < (*pcoordsize)/2; ++i){
			y = *(pcoords+i*2);
			x = *(pcoords+i*2+1);
			for (int j = 0; j < coordinates.size()/2; ++j){
				if(y==coordinates[j*2] && x==coordinates[j*2+1]){
					if(*invincible)
						return false;
					if(*shieldon){
						*shieldon = false;
						destroyed=true;
						return false;
					}
					return true;
				}
			}
		}
	}
	return false;
}

//-------------------------------------------------------------------------------------//
//	STEPLEFT METHOD
//- Moves obstacle y coordinate left 1 when called.
//- Every 5 refreshes move x coordinate up or down.
//- If a character reaches top or bottem, move to other side
void Gobstacle::stepLeft(){
	counter++;
	for (int i = 0; i < coordinates.size(); i++){
		if(i%2 != 0) coordinates[i]--;
	}
	if(counter==5){
		counter = 0;
		for (int i = 0; i < coordinates.size(); i++){
			if(i%2 == 0 && direction == 1) 
				coordinates[i] = (coordinates[i]+direction-7-offset)%24+7+offset;
			else if(i%2 == 0 && direction != 1){
				coordinates[i] -= 1;
				if (coordinates[i] == 6+offset)
					coordinates[i] = 23+7+offset;
			}
		}
	}
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Loops through all coordinates, and prints the corresponding character to screen.
//- If Invincible is on, remove colour pair.
void Gobstacle::printToTerminal(){
	if(!destroyed){
		if(!(*invincible))
			attron(COLOR_PAIR(6));
		for(int i = 0; i < word.size(); ++i){
			mvaddch(coordinates[i*2],coordinates[i*2+1],word.at(i));
		}
		if(!(*invincible))
			attroff(COLOR_PAIR(6));
	}
}

//empty destructor, because dragon.
Gobstacle::~Gobstacle(){
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
