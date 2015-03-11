#include <stdio.h>
#include <string>
#include <stdlib.h>

#include "../src/Textline.h"
#include "../src/Highscorelist.h"
#include "../src/Obstacle.h"
using namespace std;

void testIsOffScreen(){
	printf("\n\033[32m----------------------------------------------------------\033[0m\n\n");
	printf("\033[34mTESTING isOffScreen, OBSTACLE\033[0m\n");
	printf("\033[33mThis is a test to see if isOffScreen() function is working correctly.\n");
	printf("The isOffScreen method should only ever return false if all the objects\nx coordinates are greater than or equal to 0. If they less than, the method will \nreturn true.\033[0m\n\n");

	bool invincible = false;
	bool shieldon = false;
	Obstacle obstacle(0, &invincible,&shieldon);

	for (int i = 100; i > -50; --i){
		printf("x coordinate: %d: %s\n",i,obstacle.isOffScreen() ? "true" : "false");
		obstacle.stepLeft();
	}
}

void testInteract(){
	printf("\n\033[32m----------------------------------------------------------\033[0m\n\n");
	printf("\033[34mTESTING interact, OBSTACLE\033[0m\n");
	printf("\033[33mThis is a test to see if interact() function is working correctly.\n");
	printf("The interact method should only ever return true if the passed in coordinates\nare equal any coordinates within the obstacle object.\nIf they are false, the method will return false.\n\n");
	printf("In this Test I check the position of my the passed in variable against \nevery position around where the obstacles coordinates can be. If there is no interaction, print false, else true\033[0m\n\n");

	bool invincible = false;
	bool shieldon = false;
	Obstacle obstacle(0, &invincible,&shieldon);

	for (int i = 0; i <= 36; ++i){
		for (int j = 99; j <= 101; ++j){
			int coords[2] = {i,j};
			int coordsize = 2;
			printf("%s\t",obstacle.interact(&coords[0],&coordsize) ? "true" : "false");
		}
		printf("\n");
	}
}

void testIsHigh(){
	printf("\n\033[32m----------------------------------------------------------\033[0m\n\n");
	printf("\033[34mTESTING ISHIGH, HIGHSCORELIST\033[0m\n");
	printf("\033[33mThis is a test to see if isHigh() function is working correctly.\n");
	printf("If passed in number is greater than any score in the highscorelist\ntext file, function should return true, else false.\033[0m\n\n");

	string playername = "TESTNAME";
	bool nameset = true;
	Highscorelist highscorelist(&playername,&nameset);
	printf("score of %d returns %s\n",-1000000,highscorelist.isHigh(-1000000) ? "true" : "false");
	printf("score of %d returns %s\n",-1,highscorelist.isHigh(-1) ? "true" : "false");
	printf("score of %d returns %s\n",0,highscorelist.isHigh(0) ? "true" : "false");
	printf("score of %d returns %s\n",1,highscorelist.isHigh(1) ? "true" : "false");
	for (int i = 100; i <= 2000; i+=100){
		printf("score of %d returns %s\n",i,highscorelist.isHigh(i) ? "true" : "false");
	}
	printf("score of %d returns %s\n",1000000,highscorelist.isHigh(1000000) ? "true" : "false");
}

//-------------------------------------------------------------------------------------//
//	MAIN FUNCTION
//- calls all Test functions
int main() {
	srand(time(NULL));
	testIsHigh();
	testInteract();
	testIsOffScreen();
}
