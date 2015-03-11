#ifndef _SLIDER_H
#define _SLIDER_H

#include <vector>

//-------------------------------------------------------------------------------------//
//	SLIDER CLASS
//- Parent class in hierarchy tree.
//- template for all classes that move left on the screen towards player.
//- contains pure virtual functions for polymorphism.
class Slider{
	public:
		Slider();
		~Slider();
		virtual bool interact(int* pcoords, int* pcoordsize) = 0;
		virtual void stepLeft() = 0;
		virtual void printToTerminal() = 0;
		virtual bool isOffScreen() = 0;
};
#endif
