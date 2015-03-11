#ifndef _GRADIENT_H
#define _GRADIENT_H

//-------------------------------------------------------------------------------------//
//	GRADIENT CLASS
//- Controls the behaivour of the borders curves.
//-	Slope can randomly jump between three gradients.
class Gradient{
	public:
		Gradient();
		~Gradient();
		int getNum();
		void nextNum();
	private:
		double number, slope, low, med, high;
		int direction, highstopper, random;
};
#endif
