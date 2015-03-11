#include <cstdlib>
#include <iostream>
#include "Gradient.h"
using namespace std; 

//-------------------------------------------------------------------------------------//
//	GRADIENT CONSTRUCTOR
//- Picks a starting direction and sets the starting slope.
//- defines the three slopes.
Gradient::Gradient(){
	number = 0;
	if(rand()%2==1) direction = 1; 
	else direction = -1;
	low = 0.05;
	med = 0.1;
	high = 0.5;
	slope = low;
	highstopper = 0;
}

//-------------------------------------------------------------------------------------//
//	GETNUM METHOD
//- returns the current slope number.
//- if slope is 6/-6, set to 5/-5.
int Gradient::getNum(){
	if(number>=6) return 5;
	else if(number<=-6) return -5;
	else return number;
}

//-------------------------------------------------------------------------------------//
//	NEXTNUM METHOD
//- increments the slope number to its next when called.
void Gradient::nextNum(){
	random = rand()%300;

	//if slope is low, chance to change
	if (slope==low){
		if (random>295) slope = med;
		if (random==0){
			slope = high;
			highstopper = 0;
		} 
	}

	//if slope is med, chance to change
	if (slope==med){
		if (random>295) slope = low;
		if (random==0){
			slope = high;
			highstopper = 0;
		} 
	} 

	//if high, forced to changed after 15 refreshes
	if (slope==high){
		highstopper++;
		if (highstopper==15){
			if (rand()%2==1) slope = low;
			else slope = med;
		}
	}

	//chance to to randomly change slopes direction
	if (slope==low && rand()%150==0) direction = direction*(-1);
	if (slope==med && rand()%150==0) direction = direction*(-1);

	//if slope hits top or bottem of screen, force change direction
	if (number>=6) direction = -1;
	if (number<=-6) direction = 1;
	number += (slope*direction);
}

//empty destructor, because dragon.
Gradient::~Gradient(){
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