#ifndef _POWERUP_H
#define _POWERUP_H

#include <vector>
#include <string>
#include "Slider.h"

//-------------------------------------------------------------------------------------//
//	POWERUP CLASS
//- Inherits from Slider
//-	All children of this class are objects that if the player interacts with them,
//	they help the player.
class Powerup: public Slider{
	public:
		Powerup(int offset);
		~Powerup();
		virtual bool interact(int* pcoords,int* pcoordsize) = 0;
		virtual void stepLeft() = 0;
		virtual void printToTerminal() = 0;
		virtual bool isOffScreen() = 0;
	private:
		std::vector<int> coordinates;

};
#endif