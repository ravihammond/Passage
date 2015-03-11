#ifndef _TEXTBLOCK_H
#define _TEXTBLOCK_H

#include "Textline.h"
#include <string>

//-------------------------------------------------------------------------------------//
//	TEXTBLOCK CLASS
//- Contains an array of multiple text lines that get displayed in the border.
//- every referesh textblock shuffles all text line objects within its array.
class Textblock{
	public:
		Textblock();
		~Textblock();
		void shuffleAll();
		char askChar(int y,int x);
		void printAll();
		void addTitle();
	private:
		Textline block[18];
};
#endif
