#ifndef _DOBSTACLE_H
#define _DOBSTACLE_H

#include <vector>
#include <string>
#include "Obstacle.h"

//-------------------------------------------------------------------------------------//
//	DOBSTACLE CLASS
//- inherits from Obstacle.
//- class to create blue bouncing obstacles for the player to dodge.
class Dobstacle: public Obstacle{
	public:
		Dobstacle(int offset,bool *invincible,bool *shieldon);
		~Dobstacle();
		bool interact(int* pcoords,int* pcoordsize);
		void stepLeft();
		void printToTerminal();
	private:
		std::vector<int> coordinates;
		std::string wordarray[6];
		std::string word;
		std::vector<char> wordchars;
		int startposition, max, min, direction, counter;
		bool *invincible;
		bool *shieldon;
		bool destroyed;
};
#endif