#ifndef _GAME_H
#define _GAME_H

#include <vector>
#include <stdlib.h>
#include <pthread.h>

#include "Textblock.h"
#include "Slider.h"
#include "Border.h"
#include "Gradient.h"
#include "Obstacle.h"
#include "Dobstacle.h"
#include "Gobstacle.h"
#include "Player.h"
#include "Trail.h"
#include "Invincible.h"
#include "Points.h"
#include "Highscorelist.h"
#include "Multiplier.h"
#include "Shield.h"

//-------------------------------------------------------------------------------------//
//	GAME CLASS
//- contains main game loop called when game starts and ends when loop finishes.
//-	contains many variables that get passed as global variables to Slider children.
class Game{
	public:
		Game(int *input,int *score,int *best);
		~Game();
		void loop();
		void initialiseBorders();
		void printBorders();
		bool gameOver(Highscorelist *highscores);
		void addTitle();
		void resetBest();
	private:
		Textblock block;
		Gradient slope;
		Player *student;
		bool stop, invincible, hasmult, shieldon, shieldwall;
		int counter, scorecounter, *score;
		int wallcounter, *input, obstrand, speed, *best;
		double timeleft, dscore, multiplier, multtimeleft;

		//this array will hold all objects that move left to utilize polymorphic behaviour
		std::vector<Slider*> obstacles;
};
#endif
