//  **************************************************************************
//  Name: Louis Ciampanelli
//  Assignment #: #10 Using Classes with Inheritance and Polymorphism
//  File Name: functions.cpp
//  **************************************************************************#ifndef WARRIOR_H
//  Compiler directives
#ifndef WEAPONS_H
#define WEAPONS_H
#include "functions.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class definitions and function prototypes go here

class Weapon
{
public:
	
	//default constructor
	Weapon();
	
	//constructor with parameters
	Weapon(int weaponType, int weaponLevel);
	
	
	//read function
	virtual void read();
	
	//set weapon type
	void setType(int weapon);
	
	//set weapon level
	void setLevel(int level);
	

	//get weapon type
	int getType() const;
	
	//get weapon level
	int getLevel() const;
	
	//modify weapon
	virtual void modify();
	
	//display function
	virtual void display() const;
	
    
private:
	//private data
	int weaponType;
	int weaponLevel;
};


// end of the compiler directives
#endif











