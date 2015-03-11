#include "Invincible.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
using namespace std;

//-------------------------------------------------------------------------------------//
//	INVINCIBLE CONSTRUCTOR
//- Randomly picks a start position for invincible.
//- Fills coordinate vector.
//- Takes invincible and timeleft to handle the powerup events and to communicate to game loop.
//- Sets Invincible sprite.
Invincible::Invincible(int offset, bool *invincible,double *timeleft) : Powerup(offset){
	this->timeleft = timeleft;
	this->invincible = invincible;
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
	sprite = '#';
}

//-------------------------------------------------------------------------------------//
//	INTERACT METHOD
//-	If passed in coordinates are equal to invincible turn invincible on and hide from display.
bool Invincible::interact(int* pcoords,int* pcoordsize){
	int y,x;
	for (int i = 0; i < (*pcoordsize)/2; ++i){
		y = *(pcoords+i*2);
		x = *(pcoords+i*2+1);
		for (int j = 0; j < coordinates.size()/2; ++j){
			if(y==coordinates[j*2] && x==coordinates[j*2+1]){
				*timeleft = 10.00;
				displayed = false;
				*invincible = true;
				return false;
			}
		}
	}
	return false;
}

//-------------------------------------------------------------------------------------//
//	STEPLEFT METHOD
//- Moves obstacle y coordinates left 1 when called. 
void Invincible::stepLeft(){
	for (int i = 0; i < coordinates.size(); i++){
		if(i%2 != 0)
			--coordinates[i];
	}
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Prints invincible to screen in blue text
void Invincible::printToTerminal(){
	if(displayed){
		attron(COLOR_PAIR(8));
		for(int i = 0; i < 6; ++i){
			mvaddch(coordinates[i*2],coordinates[i*2+1],sprite);
		}
		attroff(COLOR_PAIR(8));
	}
}

//-------------------------------------------------------------------------------------//
//	OFFSCREEN METHOD
//- Loops through all coordinates, if all are < 0 set offscreen to false to delete object.
bool Invincible::isOffScreen(){
	bool offscreen = true;
	for (int i = 0; i < coordinates.size()/2; ++i){
		if (coordinates[i*2+1]>0)
			offscreen = false;
	}
	return offscreen;
}

//empty destructor, because dragon.
Invincible::~Invincible(){
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
