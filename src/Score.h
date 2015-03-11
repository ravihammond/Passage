#ifndef _SCORE_H
#define _SCORE_H

#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------//
//	SCORE CLASS
//- Contains the current name and score for a player in the highscores list.
class Score{
	public:
		Score(std::string line);
		~Score();
		int getScore();
		std::string getName();
		std::string getString();
		std::string getTextString();
		void setScore(int score);
	private:
		int score;
		std::string name;
	};
#endif
