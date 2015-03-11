#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "Player.h"
using namespace std;

//-------------------------------------------------------------------------------------//
//	PLAYER CONSTRUCTOR
//- Initializes shield coordinated and player coordinates.
//- Sets the starting postion, velocity and acceleration.
//- Sets player and shield sprites.
Player::Player(bool *shieldon,bool *invincible,double *timeleft){
	this->timeleft = timeleft;
	this->invincible = invincible;
	counter = 0;
	this->shieldon = shieldon;
	accel = 0.07;
	vel = 0.0;
	pos = 10.0;
	coordsize = 6;
	coordinates[0]=10;
	coordinates[1]=20;
	coordinates[2]=10;
	coordinates[3]=21;
	coordinates[4]=10;
	coordinates[5]=22;
	sprite = 'v';
	
	shieldcoordinates.push_back(0);
	shieldcoordinates.push_back(21);
	shieldcoordinates.push_back(0);
	shieldcoordinates.push_back(23);
	shieldcoordinates.push_back(0);
	shieldcoordinates.push_back(24);
	shieldcoordinates.push_back(0);
	shieldcoordinates.push_back(23);
	shieldcoordinates.push_back(0);
	shieldcoordinates.push_back(21);
	shieldsprite = "-\\|/-";
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Loops through all coordinates, and prints the corresponding character to screen.
//- If shield is on, also prints it to screen.
void Player::printToTerminal(){
	attron(COLOR_PAIR(3));
	for(int i = 0; i < 3; ++i){
		mvaddch(coordinates[i*2],
				coordinates[i*2+1],
				sprite);
	}
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(11));
	if(*shieldon){
		for(int i = 0; i < shieldcoordinates.size()/2; ++i){
			mvaddch(shieldcoordinates[i*2],
					shieldcoordinates[i*2+1],
					shieldsprite[i]);
		}
	}
}
	
//-------------------------------------------------------------------------------------//
//	MOVE DOWN METHOD
//- When called, changes players acceleration to positive.
//- When called, changes players sprit to 'v'.
void Player::moveDown(){
	accel = 0.07;
	sprite = 'v';
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- When called, changes players acceleration to negative.
//- When called, changes players sprit to '^'.
void Player::moveUp(){
	accel = -0.07;
	sprite = '^';
}

//-------------------------------------------------------------------------------------//
//	STEP TIME METHOD
//- Adds accel to vel, and then adds vel to players position.
//- Caps the players velocity and +-0.4.
//- Applies the postion changes to the player and shields coorddinates.
void Player::stepTime(){
	vel += accel;
	if(vel > 0.4) vel = 0.4;
	if(vel < -0.4) vel = -0.4;
	pos += vel;
	for (int i = 0; i < coordsize; i++){
		if(i%2 == 0){
			coordinates[i] = (int)pos;
		}
	}
	shieldcoordinates[0]=(int)pos-2;
	shieldcoordinates[2]=(int)pos-1;
	shieldcoordinates[4]=(int)pos;
	shieldcoordinates[6]=(int)pos+1;
	shieldcoordinates[8]=(int)pos+2;
}

//-------------------------------------------------------------------------------------//
//	GET COORDINATES METHOD
//- returns a pointer to the first int element of the players coordinates.
int* Player::getCoordinates(){
	return &coordinates[0];
}

//-------------------------------------------------------------------------------------//
//	GET COORD SIZE METHOD
//- returns the total size of the players coordinates.
int* Player::getCoordSize(){
	return &coordsize;
}

//-------------------------------------------------------------------------------------//
//	GET HEIGHT METHOD
//- Returns a copy of the first int element of the players coordinates.
int Player::getHeight(){
	return coordinates[0];
}

//-------------------------------------------------------------------------------------//
//	MOVE TO CENTER METHOD
//- When this function is called, moves player to the middle of the screen and
//	sets their velocity to 0.
void Player::moveToCenter(){
	pos = 18;
	vel = 0;
}

//empty destructor, because dragon.
Player::~Player(){
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
