#ifndef _PLAYER_H
#define _PLAYER_H

#include <vector>
#include <string>

//-------------------------------------------------------------------------------------//
//	PLAYER CLASS
//- Displays the player sprite. The user must guide the sprite to avoid obstacles,
//	walls, and pick up power-ups.
class Player{
	public:
		Player(bool *shieldon,bool *invincible,double *timeleft);
		~Player();
		void printToTerminal();
		void moveDown();
		void moveUp();
		void stepTime();
		int* getCoordinates();
		int* getCoordSize();
		int getHeight();
		void moveToCenter();
	private:
		std::vector <int> shieldcoordinates;
		bool *shieldon;
		double pos;
		std::string shieldsprite;
		char sprite;
		int coordsize;
		double accel;
		double vel;
		int coordinates[6];
		int counter;
		bool *invincible;
		double *timeleft;

};
#endif