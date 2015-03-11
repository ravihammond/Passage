#ifndef _BORDER_H
#define _BORDER_H

#include <vector>
#include "Textblock.h"
#include "Textline.h"
#include "Slider.h"

//-------------------------------------------------------------------------------------//
//	BORDER CLASS
//- inherits from Slider.
//- class to create the borders on top and bottom of screen.
class Border: public Slider{
	public:
		Border(int offset, Textblock *blockp,bool *shieldon,bool *shieldwall);
		~Border();
		void stepLeft();
		bool interact(int* pcoords,int* pcoordsize);
		void printToTerminal();
		bool isOffScreen();
	private:
		std::vector<int> coordinates;
		Textblock *block;
		bool *shieldon, *shieldwall;
		int *input;
};
#endif
