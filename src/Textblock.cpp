#include "Textblock.h"
#include "Textline.h"
#include <ncurses.h>
#include <stdio.h>
using namespace std;

//-------------------------------------------------------------------------------------//
//	TEXTBLOCK CONSTRUCTOR
//- Empty because nothing needs to be done for textblock at initialization.
Textblock::Textblock(){
}

//-------------------------------------------------------------------------------------//
//	SHUFFLE ALL METHOD 
//- Calls the shuffle method on every object within its array.
void Textblock::shuffleAll(){
	for (int i = 0; i < 18; ++i){
		block[i].shuffle();
	}
}

//-------------------------------------------------------------------------------------//
//	SHUFFLE ALL METHOD 
//- calls the getCharacter() method on an object within its array.
//- Y parameter refers to the block array element and x refers to the character within that objects array.
char Textblock::askChar(int y, int x){
	if(y<=12)
		return block[y-1].getCharacter(x);
	else
		return block[y-19].getCharacter(x);
}

//-------------------------------------------------------------------------------------//
//	PRINT METHOD 
//- Prints every character of the array within the object contained in Text blocks array.
void Textblock::printAll(){
	for (int j = 0; j < 10; ++j){
		for (int i = 1; i <= 100; ++i){
			printw("%c",block[j].getCharacter(i));
		}
		printw("\n");
	}
}

//-------------------------------------------------------------------------------------//
//	ADD TITLE METHOD 
//- Swaps characters out with the array of objects in order to print the title on the starting menu.
void Textblock::addTitle(){
	//printing 'P'
	block[1].addCharacter(26,'#'); block[1].addCharacter(27,'#');
	block[1].addCharacter(28,'#'); block[1].addCharacter(29,'#');
	block[1].addCharacter(30,'#'); block[1].addCharacter(31,'#');
	block[2].addCharacter(26,'#'); block[2].addCharacter(31,'#');
	block[3].addCharacter(26,'#'); block[3].addCharacter(27,'#');
	block[3].addCharacter(28,'#'); block[3].addCharacter(29,'#');
	block[3].addCharacter(30,'#'); block[3].addCharacter(31,'#'); 
	block[4].addCharacter(26,'#'); block[5].addCharacter(26,'#'); 
	
	//printing 'A'
	block[1].addCharacter(33,'#'); block[1].addCharacter(34,'#');
	block[1].addCharacter(35,'#'); block[1].addCharacter(36,'#');
	block[1].addCharacter(37,'#'); block[1].addCharacter(38,'#');
	block[2].addCharacter(33,'#'); block[2].addCharacter(38,'#');
	block[3].addCharacter(33,'#'); block[3].addCharacter(34,'#');
	block[3].addCharacter(35,'#'); block[3].addCharacter(36,'#');
	block[3].addCharacter(37,'#'); block[3].addCharacter(38,'#'); 
	block[4].addCharacter(33,'#'); block[4].addCharacter(38,'#'); 
	block[5].addCharacter(33,'#'); block[5].addCharacter(38,'#'); 


	//printing 'S'
	block[1].addCharacter(40,'#'); block[1].addCharacter(41,'#');
	block[1].addCharacter(42,'#'); block[1].addCharacter(43,'#');
	block[1].addCharacter(44,'#'); block[1].addCharacter(45,'#');
	block[2].addCharacter(40,'#'); block[3].addCharacter(40,'#');
	block[3].addCharacter(41,'#'); block[3].addCharacter(42,'#');
	block[3].addCharacter(43,'#'); block[3].addCharacter(44,'#');
	block[3].addCharacter(45,'#'); block[4].addCharacter(45,'#'); 
	block[5].addCharacter(40,'#'); block[5].addCharacter(41,'#'); 
	block[5].addCharacter(42,'#'); block[5].addCharacter(43,'#'); 
	block[5].addCharacter(44,'#'); block[5].addCharacter(45,'#');
	
	//printing 'S'
	block[1].addCharacter(47,'#'); block[1].addCharacter(48,'#');
	block[1].addCharacter(49,'#'); block[1].addCharacter(50,'#');
	block[1].addCharacter(51,'#'); block[1].addCharacter(52,'#');
	block[2].addCharacter(47,'#'); block[3].addCharacter(47,'#');
	block[3].addCharacter(48,'#'); block[3].addCharacter(49,'#'); 
	block[3].addCharacter(50,'#'); block[3].addCharacter(51,'#'); 
	block[3].addCharacter(52,'#'); block[4].addCharacter(52,'#'); 
	block[5].addCharacter(47,'#'); block[5].addCharacter(48,'#'); 
	block[5].addCharacter(49,'#'); block[5].addCharacter(50,'#'); 
	block[5].addCharacter(51,'#'); block[5].addCharacter(52,'#');

	//printing 'A'
	block[1].addCharacter(54,'#'); block[1].addCharacter(55,'#');
	block[1].addCharacter(56,'#'); block[1].addCharacter(57,'#');
	block[1].addCharacter(58,'#'); block[1].addCharacter(59,'#');
	block[2].addCharacter(54,'#'); block[2].addCharacter(59,'#');
	block[3].addCharacter(54,'#'); block[3].addCharacter(55,'#');
	block[3].addCharacter(56,'#'); block[3].addCharacter(57,'#');
	block[3].addCharacter(58,'#'); block[3].addCharacter(59,'#'); 
	block[4].addCharacter(54,'#'); block[4].addCharacter(59,'#'); 
	block[5].addCharacter(54,'#'); block[5].addCharacter(59,'#');

	//printing 'G'
	block[1].addCharacter(61,'#'); block[1].addCharacter(62,'#');
	block[1].addCharacter(63,'#'); block[1].addCharacter(64,'#');
	block[1].addCharacter(65,'#'); block[1].addCharacter(66,'#');
	block[2].addCharacter(61,'#'); block[3].addCharacter(61,'#');
	block[3].addCharacter(64,'#'); block[3].addCharacter(65,'#');
	block[3].addCharacter(66,'#'); block[4].addCharacter(61,'#'); 
	block[4].addCharacter(66,'#'); block[5].addCharacter(61,'#'); 
	block[5].addCharacter(62,'#'); block[5].addCharacter(63,'#'); 
	block[5].addCharacter(64,'#'); block[5].addCharacter(65,'#'); 
	block[5].addCharacter(66,'#');

	//printing 'E'
	block[1].addCharacter(68,'#'); block[1].addCharacter(69,'#');
	block[1].addCharacter(70,'#'); block[1].addCharacter(71,'#');
	block[1].addCharacter(72,'#'); block[1].addCharacter(73,'#');
	block[2].addCharacter(68,'#'); block[3].addCharacter(68,'#');
	block[3].addCharacter(69,'#'); block[3].addCharacter(70,'#'); 
	block[3].addCharacter(71,'#'); block[3].addCharacter(72,'#'); 
	block[3].addCharacter(73,'#'); block[4].addCharacter(68,'#'); 
	block[5].addCharacter(68,'#'); block[5].addCharacter(69,'#'); 
	block[5].addCharacter(70,'#'); block[5].addCharacter(71,'#'); 
	block[5].addCharacter(72,'#'); block[5].addCharacter(73,'#');
}

//empty decontructor, because dragon.
Textblock::~Textblock(){
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