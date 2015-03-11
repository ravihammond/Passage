#include "Obstacle.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
using namespace std;

//-------------------------------------------------------------------------------------//
//	OBSTACLE CONSTRUCTOR
//- Randomly picks a word to use, and position of dobstacle.
//- Takes invincible and shieldon to handle the powerup events.
Obstacle::Obstacle(int offset, bool *invincible,bool *shieldon) : Slider(){
	this->shieldon = shieldon;
	this->invincible=invincible;
	wordarray[0] = "ASSIGNMENT";
	wordarray[1] = "EXTENSION";
	wordarray[2] = "TUTORIAL";
	wordarray[3] = "PRACTICAL";
	wordarray[4] = "WORKSHOP";
	wordarray[5] = "LECTURE";
	word = wordarray[rand()%6];
	startposition = 7+offset+rand()%(25-word.size());	
	for(int i = 1; i <= word.size()*2; ++i){
		if(i%2 != 0){
			coordinates.push_back(startposition+i/2);
		}else{
			coordinates.push_back(100);
		}
	}
	destroyed = false;
}

//-------------------------------------------------------------------------------------//
//	INTERACT METHOD
//-	If passed in coordinates are equal to obstacle return true, else false.
//- If shield is on hide obstacle and return false.
//- If Invincible is on return false.
bool Obstacle::interact(int* pcoords,int* pcoordsize){
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
void Obstacle::stepLeft(){
	for (int i = 0; i < coordinates.size(); i++){
		if(i%2 != 0){
			--coordinates[i];
		}
	}
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Loops through all coordinates, and prints the corresponding character to screen.
//- If Invincible is on, remove colour pair.
void Obstacle::printToTerminal(){
	if(!destroyed){
		if(!(*invincible))
			attron(COLOR_PAIR(4));
		for(int i = 0; i < word.size(); ++i){
			mvaddch(coordinates[i*2],coordinates[i*2+1],word.at(i));
		}
		if(!(*invincible))
			attroff(COLOR_PAIR(4));
	}
}

//-------------------------------------------------------------------------------------//
//	OFFSCREEN METHOD
//- Loops through all coordinates, if all are < 0 set offscreen to false to delete object.
bool Obstacle::isOffScreen(){
	bool offscreen = true;
	for (int i = 0; i < coordinates.size()/2; ++i){
		if (coordinates[i*2+1]>0)
			offscreen = false;
	}
	return offscreen;
}

//empty destructor, because dragon.
Obstacle::~Obstacle(){
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