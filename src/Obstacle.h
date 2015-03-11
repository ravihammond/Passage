#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include <vector>
#include <string>
#include "Slider.h"

//-------------------------------------------------------------------------------------//
//	OBSTACLE CLASS
//- class to create red static obstacles for the player to dodge.
class Obstacle: public Slider{
	public:
		Obstacle(int offset, bool *invincible,bool *shieldon);
		~Obstacle();
		bool interact(int* pcoords,int* pcoordsize);
		void stepLeft();
		void printToTerminal();
		bool isOffScreen();
	private:
		std::vector<int> coordinates;
		std::string word;
		std::vector<char> wordchars;
		int startposition;
		std::string wordarray[6];
		bool *invincible;
		bool *shieldon;
		bool destroyed;
};
#endif