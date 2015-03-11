#ifndef _INVINCIBLE_H
#define _INVINCIBLE_H

#include <vector>
#include <string>
#include "Powerup.h"

//-------------------------------------------------------------------------------------//
//	INVINCIBLE CLASS
//- Inherits from Powerup
//-	When the player interacts with this object, for a timer of 10, 
//	all obstacles turn white and the player can pass through them.
//- The timer counts down, when it reaches 0 everything goes back to normal.
class Invincible: public Powerup{
	public:
		Invincible(int offset, bool *invincible, double *timeleft);
		~Invincible();
		bool interact(int* pcoords,int* pcoordsize);
		void stepLeft();
		void printToTerminal();
		bool isOffScreen();
	private:
		std::vector<int> coordinates;
		int startposition;
		char sprite;
		bool displayed;
		bool *invincible;
		double *timeleft;
};
#endif