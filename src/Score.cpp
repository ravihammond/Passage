#include <stdio.h>
#include <fstream>
#include <ncurses.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

#include "Score.h"

//-------------------------------------------------------------------------------------//
//	SCORE CONSTRUCTOR
//- Loops through the passed string and puts everything before the ',' into the 'name' variable.
//- Everything after the ',' gets converted into an int and stored into the score variable.
Score::Score(string line){
	int element = 0;
	string scorestring;
	char current;
	for (int i = 0; i < line.size(); ++i){
		current = line.at(i);
		if(current==','){
			element++;
			continue;
		}
		if(element==0){
			name += current;
		}else if(element==1){
			scorestring += current;
		}
		
	}

	score = atoi(scorestring.c_str());
}

//-------------------------------------------------------------------------------------//
//	GET SCORE METHOD
//- returns the objects score.
int Score::getScore(){
	return score;
}

//-------------------------------------------------------------------------------------//
//	GET NAME METHOD
//- 
string Score::getName(){
	return name;
}

//-------------------------------------------------------------------------------------//
//	GET SCORE METHOD
//- 
string Score::getString(){
	char buffer [10];
	sprintf(buffer,"%d",score);
	return name + "\t" + buffer;
}

//-------------------------------------------------------------------------------------//
//	GET TEXT STRING METHOD
//- Returns name and score variable appended as a string, seperated by a ','.
string Score::getTextString(){
	char buffer [10];
	sprintf(buffer,"%d",score);
	return name + "," + buffer;
}
//-------------------------------------------------------------------------------------//
//	SET SCORE METHOD
//- Sets the score variable to whatever is passed in.
void Score::setScore(int score){
	this->score = score;
}

//-------------------------------------------------------------------------------------//
//	GET SCORE METHOD
//- 
//empty destructor, because dragon.
Score::~Score(){
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
