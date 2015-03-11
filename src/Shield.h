#ifndef _SHIELD_H
#define _SHIELD_H

#include <vector>
#include <string>
#include "Powerup.h"

//-------------------------------------------------------------------------------------//
//	SHIELD CLASS
//- Inherits from Powerup
//-	When player interacts with this powerup, a green shield surrounds them and they 
//	can survive one woukd-be death.
class Shield: public Powerup{
	public:
		Shield(int offset,bool *shieldon);
		~Shield();
		bool interact(int* pcoords,int* pcoordsize);
		void stepLeft();
		void printToTerminal();
		bool isOffScreen();
	private:
		std::vector<int> coordinates;
		int startposition;
		char sprite;
		bool displayed;
		bool *shieldon;
		
};
#endif