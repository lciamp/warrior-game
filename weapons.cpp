//  **************************************************************************
//  Name: Louis Ciampanelli
//  Assignment #: #10 Using Classes with Inheritance and Polymorphism
//  File Name: functions.cpp
//  **************************************************************************#ifndef WARRIOR_H
//  Compiler directives ********************************************************
#include "weapons.h"
#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

//  Class member function implementations **************************************
//

// default constructor
Weapon::Weapon()		
{
	weaponType = 0;		// default values for type and level
	weaponLevel = 25;
}

//constructor with parameters
Weapon::Weapon (int type, int level)
{
	weaponType = type;		//sets the parameters
	weaponLevel = level;
}

// set functions****************************************************



void Weapon::read()
{
	int wepType, wepLev;
	string choice[7] = {"Sword", "Axe", "Bow", "Knife", 
		"Wand", "Staff", "Fire Stick"};
	
	cout << "Select a weapon: " << endl;
	for (int i = 0; i < 7; i++)
		cout << i+1 << " - " << choice[i] << endl;
	cin >> wepType;
	while (wepType < 1 || wepType > 8)
	{
		cout << "Invalid Number, Try again" << endl;
		cin >> wepType;
	}
	weaponType = --wepType;
	
	cout << "Please enter a level for your weapon(0-200): " << endl;
	cin >> wepLev;
	while (wepLev < 0 || wepLev > 200)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> wepLev;
	}
	weaponLevel = wepLev;
}


//set methods
void Weapon::setType(int w)
{
	weaponType = w;
}

void Weapon::setLevel(int level)
{
	weaponLevel = level;
}


// get methods

// returns the valuse of weaponType
int Weapon::getType() const
{
	return weaponType;
}

//reteurns the valuse of weapoLevel
int Weapon::getLevel() const
{
	return weaponLevel;
}

void Weapon::modify() 
{
	int randWep, newLevel;
	
	//random numbers
	randWep = randomGenerator(-15, 15);
	// weapon level
	newLevel = getLevel();
	//add random number
	newLevel += randWep;
	//set new level
	weaponLevel = newLevel;
}
	
	

//displays the values for the private data of the class
void Weapon::display() const
{
	string choice[7] = {"Sword", "Axe", "Bow", "Knife", 
		"Wand", "Staff", "Fire Stick"};
	
	cout << left;
	cout << setw(20) << "Weapon Type: " << choice[weaponType] << endl;
	cout << setw(20) << "Weapon Level: "  << weaponLevel << endl;
}


// Non-member function implementations *****************************************




