#ifndef _TRAIL_H
#define _TRAIL_H

#include <vector>
#include <string>
#include "Slider.h"

//-------------------------------------------------------------------------------------//
//	TRAIL CLASS
//- Inherits from Slider
//- spawns a dot directly behind the player. creates aa smoke effect.
class Trail: public Slider{
	public:
		Trail(int position);
		~Trail();
		bool interact(int* pcoords,int* pcoordsize);
		void stepLeft();
		void printToTerminal();
		bool isOffScreen();
	private:
		std::vector<int> coordinates;
		char word;
};
#endif