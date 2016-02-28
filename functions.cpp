//  **************************************************************************
//  Name: Louis Ciampanelli
//  Assignment #: #10 Using Classes with Inheritance and Polymorphism
//  File Name: functions.cpp
//  **************************************************************************
//  Compiler directives ******************************************************
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include "functions.h"
#include "player.h"
using namespace std;

//  Class member function implementations **************************************


// Non-member function implementations *****************************************

//function that generates a random number, bet a min and max value
int randomGenerator(int min, int max)
{	
	int x;
	x = min + rand() % ( max - min + 1 ); // assign random number to x
	
	return x;
}

// i never use this
// do-while loops seem backwards to me
int validate(int min, int max, int test)
{
	int x = test;
	do {
		cout << "Invalid Choice, Please try again ("
		<< min << "-" << max << endl;
		cin >> x;
	} while (x < min || x > max);
	
	return x;
}

// description of the game
void description()
{
	cout << "This is a game that simulates a fantasy battel "
	<< "between upto 10 players." 
	<< endl << "You can choose for your players to be either "
	<< "a Warrior or a Wizard." << endl
	<< "The game will then simulate them attacking each other "
	<< "25 times."
	<< endl << endl;
}

// function that asks the user how many players they want, and returns the number
int howMany()
{
	int num;
	cout << "How many players would you like?(0-10): " << endl;
	cin >> num;
	while (num < 0 || num >10)
		{
			cout << "Invalid Number, Try Again: " << endl;
			cin >> num;
		}
	return num;
}




