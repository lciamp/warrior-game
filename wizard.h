//  **************************************************************************
//  Name: Louis Ciampanelli
//  Assignment #: #10 Using Classes with Inheritance and Polymorphism
//  File Name: functions.cpp
//  **************************************************************************#ifndef WARRIOR_H
//  ****************************************************************************
#ifndef WIZZARD_H
#define WIZZARD_H


#include "player.h"

// Wizard class
class Wizard : public Player 
{

public :
	
	//default constructor
	Wizard();
	
	//constructor with parameters
	Wizard(string n, int l, int wepType, int wepLevel, int m);
	
	// read in all data
	virtual void read();
	
	// modify data
	virtual void modify();
	
	// set functions
	
	//get magic
	virtual void setPower(int m);
	
	//set weapon
	void setWeapon(int w);
	
	//get functions
	
	//get magic
	virtual int getPower() const;
	
	//get weapon 
	int getWeapon() const;
    
    //overloaded opperators
    
    //add to strenght
    void operator += (const int num);
    
    //subtract from strenght
    void operator -= (const int num);
	
	// display the player/wizard/weapon data
	virtual void display() const;	
	
private : 
	
	int magic;
	Weapon weaponTwo;
	
};

///////////////////////////////////////////////////////////////////
//non member read in / read out overloaded operators

//out
ostream& operator << (ostream& out, const Wizard& w1);

//in
istream& operator >> (istream& in, Wizard& w1);







#endif


