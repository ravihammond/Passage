#include "Textline.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------//
//	TEXTLINE CONSTRUCTOR
//- Builds & defines initial print variable conditions.
//- Builds the string array.
Textline::Textline(){
	currentword = rand()%10;
	currentletter = 0;
	start = 0;
	wordarray[0] = "ASSIGNMENT|";
	wordarray[1] = "EXAM|";
	wordarray[2] = "TUTORIAL|";
	wordarray[3] = "PRACTICAL|";
	wordarray[4] = "WORKSHOP|";
	wordarray[5] = "LECTURE|";
	wordarray[6] = "TEST|";
	wordarray[7] = "SMALLGROUPDISCOVERY|";
	wordarray[8] = "ESSAY|";
	wordarray[9] = "EXTENSION|";
	nextchar = wordarray[currentword].at(currentletter);
	for (int i = 0; i < 100; ++i){
		shuffle();
	}
}

//-------------------------------------------------------------------------------------//
//	SHUFFLE METHOD
//- appends next char to the next spot in array
//- redefines nextchar or selects a new word
void Textline::shuffle(){
	*(array+start%100) = nextchar;
	start++;
	if(currentletter < (wordarray[currentword].length()-1)){
		currentletter++;
		nextchar = wordarray[currentword].at(currentletter);
	}else{
		currentword = rand()%10;
		currentletter = 0;
		nextchar = wordarray[currentword].at(currentletter);
	}
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD
//- Prints all characters within the array to the console using circular printing method.
void Textline::print(){
	for(int i = 0; i < 100; ++i){
		printf("%c",(*(array+((start+i)%100))));
	}
	printf("\n");
}

//-------------------------------------------------------------------------------------//
//	GET CHARACTER METHOD
//- returns the character in array according to the passed in x coordinate.
char Textline::getCharacter(int x){
	return *(array+((start+x-1)%100));
}

//-------------------------------------------------------------------------------------//
//	ADD CHARACTER METHOD
//- changes character in array with passed in char at passed in postion.
void Textline::addCharacter(int position, char character){
	array[position] = character;
}

//empty contructor, because dragon.
Textline::~Textline(){
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