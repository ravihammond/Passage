#include <stdio.h>
#include <fstream>
#include <ncurses.h>
#include <iostream>
#include <ctype.h>

#include "Highscorelist.h"
using namespace std;

//-------------------------------------------------------------------------------------//
//	HIGHSCORELIST CONSTRUCTOR
//- Takes the current user and if a name has been set.
//- opens the highscores text file, for each line, add user and score as object to array.
Highscorelist::Highscorelist(string *playername,bool *nameset){
	this->nameset = nameset;
	this->playername = playername;

	ifstream textfile ("./src/highscores.txt");
	string line;
	arraysize=0;
	for (int i = 0; getline(textfile,line); ++i){
		Highscores[i] = new Score(line);
		arraysize++;
	}
	textfile.close();
}

//-------------------------------------------------------------------------------------//
//	ADD TO ARRAY METHOD
//- Loops through everyone in highscores list, if user is in highscores checks to see if
//	their score is higher then previous. If it is, shuffle everyone with a score lower
//	than theirs and insert them so all the scores descend from top to bottom.
void Highscorelist::addToArray(int score){
	char buffer [10];
	sprintf(buffer,"%d",score);

	//name checking for loop described above
	for (int i = 0; i < arraysize; ++i){
		if(*playername==Highscores[i]->getName()){
			if(score<Highscores[i]->getScore()){
				return;
			}else{
				attron(COLOR_PAIR(11));
				mvprintw(16,46,"New highscore!");
				attroff(COLOR_PAIR(11));
				if(i==0){
					Highscores[0]->setScore(score);
					return;
				}else{
					for (int j = i; 0 < j; --j){
						if(score>Highscores[j-1]->getScore()){
							Highscores[j] = Highscores[j-1];
							if(j==1) 
								Highscores[0] = new Score(*playername+","+buffer);
						}else{
							Highscores[j] = new Score(*playername+","+buffer);
							break;
						}
					}
					return;
				}
			}
		}
	}

	//inserts player into highscores so that all scores ascend from top to bottom
	attron(COLOR_PAIR(11));
	mvprintw(16,46,"New highscore!");
	attroff(COLOR_PAIR(11));
	for (int i = 0; i < arraysize; ++i){
		if(score>Highscores[i]->getScore()){
			for(int j=arraysize; j > i; --j){
				if(j!=10)
					Highscores[j] = Highscores[j-1];
			}
			Highscores[i] = new Score(*playername+","+buffer);
			if(arraysize<10)
				arraysize++;
			return;
		}
	}

	//if array size is less than max (10), append player and their score to array
	if(arraysize<10){
		Highscores[arraysize] = new Score(*playername+","+buffer);
		arraysize++;
	}
	
}

//-------------------------------------------------------------------------------------//
//	WRITE TO FILE METHOD
//- Writes everything within the object to the array into the highscores file.
void Highscorelist::writeToFile(){
	ofstream writefile("./src/highscores.txt");
	for (int i = 0; i < arraysize; ++i){
		writefile << Highscores[i]->getTextString()<<endl;
	}
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Prints all highscores from object array to screen.
//- If current highscore name is equala to current user make text green.
void Highscorelist::printToScreen(){
	attron(COLOR_PAIR(12));
	mvprintw(9,46,"HIGHSCORES");
	attroff(COLOR_PAIR(12));
	int line = 10;
	for (int i = 0; i < arraysize; ++i){
		if(*playername==Highscores[i]->getName()){
			attron(COLOR_PAIR(11));
		}
		mvprintw(line,40,"%d",i+1);
		mvprintw(line,43,"%s",Highscores[i]->getName().c_str());
		mvprintw(line,58,"%d",Highscores[i]->getScore());
		if(*playername==Highscores[i]->getName()){
			attroff(COLOR_PAIR(11));
		}
		line++;
	}
}

//-------------------------------------------------------------------------------------//
//	IS HIGH METHOD
//- Checks to see if passed in score is higher than any top high score.
bool Highscorelist::isHigh(int score){
	if(arraysize==0) return true;
	for (int i = 0; i < arraysize; ++i){
		if((score>Highscores[arraysize-1]->getScore() && score>=Highscores[i]->getScore()) || arraysize<10){
			return true;
		}
	}
	return false;
}

//-------------------------------------------------------------------------------------//
//	WRITE TO FILE METHOD
//- Writes everything within the object to the array into the highscores file.
void Highscorelist::changeName(){

	//clears
	curs_set(1);
	for (int i = 9; i < 20; ++i){
		move(i,0); clrtoeol();
	}
	char chplayername[10000];
	mvprintw(14,40,"type your name: ");
	refresh();
	bool invalid = true;
	bool allclear;

	//loops the users input until a valid name is entered
	while(invalid){
		allclear = true;
		move(14,55); clrtoeol(); move(14,56);
		getstr(chplayername);
		*playername = chplayername;

		//checks to see i input is between 2 and 12 characters long
		if(playername->size()<2 || playername->size()>12){
				move(16,0); clrtoeol();
				attron(COLOR_PAIR(9));
				mvprintw(16,34,"name must be 2-12 characters long");
				attroff(COLOR_PAIR(9));
				allclear = false;
		}

		//checks to see if input not a letter
		for (int i = 0; i < playername->size(); ++i){
			if(!isalpha(chplayername[i])){
					move(16,0); clrtoeol();
					attron(COLOR_PAIR(9));
					mvprintw(16,40,"only letters allowed");
					attroff(COLOR_PAIR(9));
					allclear = false;
			}
		}

		//makes users input all upper-casee
		for (int i = 0; i < playername->size(); ++i){
			(*playername)[i] = toupper((*playername)[i]);
		}
		if(allclear){
			move(10,4); clrtoeol();
			move(12,4); clrtoeol();
			invalid = false;
		}
	}

	//clears screen
	for (int i = 9; i < 20; ++i){
		move(i,0); clrtoeol();
	}
	curs_set(0);
}

//empty destructor, because dragon.
Highscorelist::~Highscorelist(){
 //             ______________
 //       ,===:'.,            `-._
 //            `:.`---.__         `-._
 //              `:.     `--.         `.
 //                \.        `.         `.
 //        (,,(,    \.         `.   ____,-`.,
 //     (,'     `/   \.   ,--.___`.'
 // ,  ,'  ,--.  `,   \.;'         `
 //  `{D, {    \  :    \;
 //    V,,'    /  /    //
 //    j;;    /  ,' ,-//.    ,---.      ,
 //    \;'   /  ,' /  _  \  /  _  \   ,'/
 //          \   `'  / \  `'  / \  `.' /
 //           `.___,'   `.__,'   `.__,'  
}
