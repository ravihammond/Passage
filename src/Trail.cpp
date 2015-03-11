#include "Trail.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
using namespace std;

//-------------------------------------------------------------------------------------//
//	TRAIL CONSTRUCTOR
//- Randomly picks a start position for invincible.
//- Sets Points sprite.
Trail::Trail(int position) : Slider(){
	coordinates.push_back(position);
	coordinates.push_back(20);
	word = '.';
}

//-------------------------------------------------------------------------------------//
//	INTERACT METHOD
//-	Player can never interact with trail, always returns false
bool Trail::interact(int* pcoords,int* pcoordsize){
	return false;
}

//-------------------------------------------------------------------------------------//
//	STEPLEFT METHOD
//- Moves obstacle y coordinate left 1 when called.
void Trail::stepLeft(){
	--coordinates[1];
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Prints trail to screen in white text
void Trail::printToTerminal(){
	mvaddch(coordinates[0],coordinates[1],word);
}

//-------------------------------------------------------------------------------------//
//	OFFSCREEN METHOD
//- Loops through all coordinates, if all are < 0 set offscreen to false to delete object.
bool Trail::isOffScreen(){
	bool offscreen = true;
	for (int i = 0; i < coordinates.size()/2; ++i){
		if (coordinates[i*2+1]>0)
			offscreen = false;
	}
	return offscreen;
}

//empty destructor, because dragon.
Trail::~Trail(){
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
