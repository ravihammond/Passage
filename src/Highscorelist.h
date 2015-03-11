#ifndef _HIGHSCORELIST_H
#define _HIGHSCORELIST_H
#include <string>

#include "Score.h"

//-------------------------------------------------------------------------------------//
//	HIGHSCORE CLASS
//- Handles interaction between program and highscore text file.
//- Contains object of all users currently on the highscores list.
//- Contains sorting algorithms to insert new highscore into list if needed.
class Highscorelist{
	public:
		Highscorelist(std::string *playername, bool *nameset);
		~Highscorelist();
		void writeToFile();
		void addToArray(int score);
		void printToScreen();
		bool isHigh(int score);
		void changeName();
	private:
		Score* Highscores[10];
		int arraysize;
		std::string *playername;
		bool *nameset;
};
#endif
