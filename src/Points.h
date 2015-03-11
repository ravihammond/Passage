#ifndef _POINTS_H
#define _POINTS_H

#include <vector>
#include <string>
#include "Powerup.h"

//-------------------------------------------------------------------------------------//
//	POINTS CLASS
//- Inherits from Slider
//-	If player interacts with Points object, 50 points are added to score and a message is displayed.
class Points: public Powerup{
	public:
		Points(int offset,double *score);
		~Points();
		bool interact(int* pcoords,int* pcoordsize);
		void stepLeft();
		void printToTerminal();
		bool isOffScreen();
	private:
		std::vector<int> coordinates;
		int startposition;
		char sprite;
		bool displayed;
		double *score;
		std::vector<int> wordcoordinates;
		std::string word;
};
#endif