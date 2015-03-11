#include "Multiplier.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
using namespace std;

//-------------------------------------------------------------------------------------//
//	MULTIPLIER CONSTRUCTOR
//- Randomly picks a start position for multiplier.
//- Fills coordinate vector.
//- Takes gobal variable as parameters to communicate to game loop.
//- Sets Multiplier sprite.
Multiplier::Multiplier(int offset,double *multiplier,bool *hasmult,double *multtimeleft) : Powerup(offset){
	this->multtimeleft = multtimeleft;
	this->hasmult = hasmult;
	this->multiplier = multiplier;
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
	sprite = 'X';
}

//-------------------------------------------------------------------------------------//
//	INTERACT METHOD
//-	If passed in coordinates are equal to multiplier, add .5 to multiplier and add 40 to timer.
bool Multiplier::interact(int* pcoords,int* pcoordsize){
	int y,x;
	for (int i = 0; i < (*pcoordsize)/2; ++i){
		y = *(pcoords+i*2);
		x = *(pcoords+i*2+1);
		for (int j = 0; j < coordinates.size()/2; ++j){
			if(y==coordinates[j*2] && x==coordinates[j*2+1]){
				if(displayed){
					*multiplier+=0.5;
					*multtimeleft = 40.00;
				}
				displayed = false;
				*hasmult = true;
				return false;
			}
		}
	}
	return false;
}

//-------------------------------------------------------------------------------------//
//	STEPLEFT METHOD
//- Moves obstacle y coordinates left 1 when called.
void Multiplier::stepLeft(){
	for (int i = 0; i < coordinates.size(); i++){
		if(i%2 != 0)
			--coordinates[i];
	}
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Prints multiplier to screen in purple text
void Multiplier::printToTerminal(){
	if(displayed){
		attron(COLOR_PAIR(10));
		for(int i = 0; i < 6; ++i){
			mvaddch(coordinates[i*2],coordinates[i*2+1],sprite);
		}
		attroff(COLOR_PAIR(10));
	}
}

//-------------------------------------------------------------------------------------//
//	OFFSCREEN METHOD
//- Loops through all coordinates, if all are < 0 set offscreen to false to delete object.
bool Multiplier::isOffScreen(){
	bool offscreen = true;
	for (int i = 0; i < coordinates.size()/2; ++i){
		if (coordinates[i*2+1]>0)
			offscreen = false;
	}
	return offscreen;
}

//empty destructor, because dragon.
Multiplier::~Multiplier(){
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
