#ifndef _TEXTLINE_H
#define _TEXTLINE_H

#include <string>

//-------------------------------------------------------------------------------------//
//	TEXTLINE CLASS
//- Contains an array of all characters that get displayed in the top and bottem borders.
//- Array has circular behaiviour. When shuffle is called, the start-printing postion moves.
class Textline{
	public:
		Textline();
		~Textline();
		void shuffle();
		void print();
		char getCharacter(int x);
		void addCharacter(int position, char character);
	private:
		int start;
		char nextchar;
		char array[100];
		std::string wordarray[10];
		int currentword;
		int currentletter;
};
#endif
