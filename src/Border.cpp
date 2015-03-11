#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include "Border.h"
using namespace std; 

//-------------------------------------------------------------------------------------//
//	BORDER CONSTRUCTOR
//- Initinalizes the posisition of the borders according to the offset.
//- Takes textblock for the borders text.
//- Gets shieldon to know if the players shield is on and student to move the player to center
Border::Border(int offset, Textblock *blockp,bool *shieldon,bool *shieldwall) : Slider(){
	this->shieldwall = shieldwall;
	this->shieldon = shieldon;
	block = blockp;
	for (int i = 1; i <= 12+offset*2; ++i){
		if(i%2 != 0){
			coordinates.push_back(i/2+1);
		}else{
			coordinates.push_back(100);
		}
	}
	for (int i = 1; i <= 12-offset*2; ++i){
		if(i%2 != 0){
			coordinates.push_back((i/2)+31+offset);
		}else{
			coordinates.push_back(100);
		}
	}
}

//-------------------------------------------------------------------------------------//
//	STEPLEFT METHOD
//- Moves borders y coordinate left 1 when called.
void Border::stepLeft(){
	for (int i = 0; i < 24; i++){
		if(i%2 != 0){
			--coordinates[i];
		}
	}
}

//-------------------------------------------------------------------------------------//
//	INTERACT METHOD
//-	If passed in coordinates are equal to borders return true, else false.
//- If shield is on, move player to center and return false.
bool Border::interact(int* pcoords,int* pcoordsize){
	int y,x;
	for (int i = 0; i < (*pcoordsize)/2; ++i){
		y = *(pcoords+i*2);
		x = *(pcoords+i*2+1);
		for (int j = 0; j < coordinates.size()/2; ++j){
			if(y==coordinates[j*2] && x==coordinates[j*2+1]){

				//if shield is on, don't kill the player
				if(*shieldon){
					*shieldwall = true;
					return false;
				}
				return true;
			}
		}
	}
	return false;
}

//-------------------------------------------------------------------------------------//
//PRINT METHOD
//- Loops through all coordinates, and prints the corresponding character to screen
//- If printed character is #, make the colour black.
void Border::printToTerminal(){
	char character;
	attron(COLOR_PAIR(1));
	for (int i = 0; i < coordinates.size()/2; ++i){
		int y = coordinates[i*2];
		int x = coordinates[i*2+1];
		character = (*block).askChar(y,x);
		if(character=='#') attron(COLOR_PAIR(13));
		mvaddch(y, x, character);
		if(character=='#'){
			attroff(COLOR_PAIR(13));
			attron(COLOR_PAIR(1));
		}
	}
	attroff(COLOR_PAIR(1));
}

//-------------------------------------------------------------------------------------//
//	OFFSCREEN METHOD
//- Loops through all coordinates, if all are < 0 set offscreen to false to delete object.
bool Border::isOffScreen(){
	bool offscreen = true;
	for (int i = 0; i < coordinates.size()/2; ++i){
		if (coordinates[i*2+1]>0)
			offscreen = false;
	}
	return offscreen;
}

//empty destructor, because dragon.
Border::~Border(){
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