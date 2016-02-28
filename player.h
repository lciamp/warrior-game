//  **************************************************************************
//  Name: Louis Ciampanelli
//  Assignment #: #10 Using Classes with Inheritance and Polymorphism
//  File Name: functions.cpp
//  **************************************************************************/  *****************************************************************************************************************************************************

//  Compiler directives
#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include "weapons.h"
#include "functions.h"

using namespace std;

// Class definitions and function prototypes go here

class Player
{
public : 

	// default constructor
	Player();

	//constructor with parameters
	Player(string n, int l, int wepType, int wepLevel);
	
	
	//player class set functions
	virtual void read();						//reads in data
	
	void setName(string);				//sets players name
	
	void setLevel(int);					//sets players level
	
	void setWeaponLevel(int l);			//sets players weapon level
	
	void setWeaponType(int type);	//sets players weapon type
	
	void setStatus(bool status);		//sets players status
	
	// player get functions
	string getName() const;				//gets players name
	
	int getLevel() const;				//gets players level
	
	virtual int getWeaponLevel()const ;			//gets the players weapon level
	
	int getWeaponType()const ;			//gets the players weapon type
	
	bool getStatus() const;				//gets players status
	
	virtual void modify() ;				//modify player

	virtual void display() const;		//displays all data
		
private:
	string name;
	int level;
	Weapon weaponOne;
	int weaponType;
	int weaponLevel;
	bool status;
};


// non member functions
Player getInfo();
void modPlayer(Player&);



// end of the compiler directives
#endif











