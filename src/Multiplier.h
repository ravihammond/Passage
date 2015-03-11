#ifndef _MULTIPLIER_H
#define _MULTIPLIER_H

#include <vector>
#include <string>
#include "Powerup.h"

//-------------------------------------------------------------------------------------//
//	MULTIPLIER CLASS
//- Inherits from Slider
//- If a player interacts with this class .5 will be added to the current score
//	multiplier and a message saying what the multiplication is will be displayed.
class Multiplier: public Powerup{
	public:
		Multiplier(int offset,double *multiplier,bool *hasmult,double *multtimeleft);
		~Multiplier();
		bool interact(int* pcoords,int* pcoordsize);
		void stepLeft();
		void printToTerminal();
		bool isOffScreen();
	private:
		std::vector<int> coordinates;
		int startposition;
		char sprite;
		bool displayed;
		double *multiplier;
		bool *hasmult;
		double *multtimeleft;
};
#endif