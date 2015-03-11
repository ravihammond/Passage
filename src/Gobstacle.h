#ifndef _GOBSTACLE_H
#define _GOBSTACLEf_H

#include <vector>
#include <string>
#include "Obstacle.h"

//-------------------------------------------------------------------------------------//
//	GOBSTACLE CLASS
//- class to create yellow scolling obstacles for the player to dodge.
class Gobstacle: public Obstacle{
	public:
		Gobstacle(int offset,bool *invincible,bool *shieldon);
		~Gobstacle();
		bool interact(int* pcoords,int* pcoordsize);
		void stepLeft();
		void printToTerminal();
	private:
		std::vector<int> coordinates;
		std::string wordarray[6];
		std::string word;
		std::vector<char> wordchars;
		int startposition, max, min, direction, counter, offset;
		bool *invincible;
		bool *shieldon;
		bool destroyed;
};
#endif