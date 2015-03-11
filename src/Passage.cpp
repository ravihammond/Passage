#include <stdio.h>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>
#include <string>

#include "Game.h"
#include "Highscorelist.h"
using namespace std;


//-------------------------------------------------------------------------------------//
//	THREAD FUNCTION
//- Loop that waits for users input.
//- Passes the input to the game loop.
void *controller(void *inputp){
	int *input = (int *)inputp;
	while (input[1] != 1) {
		input[0] = getchar();
	}
	return NULL;
}

//-------------------------------------------------------------------------------------//
//	MAIN FUNCTION
//- Initializes variables and colour pairs.
//- containes loop for main menu.
int main() {
	srand(time(NULL));

	//initializing variables
	string playername;
	bool nameset = false;
	Highscorelist highscores(&playername,&nameset);
	pthread_t thread;
	int *inputp ,input[3] = {0,0,0};
	inputp = &input[0];
	int control;
	int initstop = 0;
	int menustop;
	int score;
	int menu;
	int best = 0;
	bool first = true;

	//starting ncurses
	initscr();
	raw();
	start_color();

	//creating colour pairs
	init_pair(1,0,1);
	init_pair(2,0,4);
	init_pair(3,0,7);
	init_pair(4,0,1);
	init_pair(5,0,6);
	init_pair(6,0,3);
	init_pair(7,3,0);
	init_pair(8,4,0);
	init_pair(9,1,0);
	init_pair(10,5,0);
	init_pair(11,2,0);
	init_pair(12,6,0);
	init_pair(13,0,0);
	
	while(initstop!=1){

		//resets game for next run
		menustop = 0;
		*(inputp+1)=0;
		Game *game = new Game(inputp,&score,&best);
		game->initialiseBorders();
		game->addTitle();

		//loop that waits for user input
		while(menustop!=1){
			clear();

			//prints menu screen
			attron(COLOR_PAIR(1));
			game->printBorders();
			attroff(COLOR_PAIR(1));
			highscores.printToScreen();

			//adds all menu text to screen
			attron(COLOR_PAIR(12));
			mvprintw(25,46,"CONTROLS");
			attroff(COLOR_PAIR(12));
			mvprintw(26,35,"MOVE UP : 'z'    MOVE DOWN : 'x'");
			mvprintw(23,31,"Press 'x' to START, 'n' to change name");
			if(!nameset){
				highscores.changeName();
				highscores.printToScreen();
				nameset = true;
			}
			attron(COLOR_PAIR(12));
			mvprintw(21,44,"USER :: ");
			attroff(COLOR_PAIR(12));
			attron(COLOR_PAIR(11));
			mvprintw(21,52,playername.c_str());
			attroff(COLOR_PAIR(11));
			refresh();

			//waits for users input
			curs_set(0);
			menu = getchar();

			//starts thread, begins game loop, kills thread when done, adds score to highscores
			if(menu == 'x' ){
				pthread_create(&thread, NULL, controller, (void *)inputp);
				game->loop();
				if(score>best)
					best = score;
				pthread_cancel(thread);
				*inputp=25;
				if(game->gameOver(&highscores)){
					highscores.addToArray(score);
					highscores.writeToFile();
				}
				refresh();
				while (getchar() != ' '){}
				menustop=1;

			//quits all loops to leave program
			}else if(menu == 'q'){
				menustop=1;
				initstop=1;

			//gives player the option to change name
			}else if(menu == 'n'){
				highscores.changeName();
				highscores.printToScreen();
				game->resetBest();
			}
		}
		delete game;
	}
	pthread_join(thread, NULL);
	endwin();
	return 0; 
}