//  **************************************************************************
//  Name: Louis Ciampanelli
//  Assignment #: #10 Using Classes with Inheritance and Polymorphism
//  File Name: functions.cpp
//  **************************************************************************#ifndef WARRIOR_H
#define WARRIOR_H


#include "player.h"

// Wizard class
class Warrior : public Player 
{
	
	public :
	
	//default constructor
	Warrior();
	
	//construstor with paramaters
	Warrior(string n, int l, int wepType, int wepLevel, int s);
	
	virtual void read();
	
	// set functions
	//set strenght
	virtual void setPower(int s);
	
	//set weapon
	void setWeapon(int w);
	
	//get functions
	
	//get magic
	virtual int getPower() const;
	
	//get weapon 
	int getWeapon() const;
	
	// modify data
	virtual void modify();
    
    //overloaded opperators
    
    //add to strenght
    void operator += (const int num);
    
    //subtract from strenght
    void operator -= (const int num);
    
	
	// display the player/wizard/weapon data
	virtual void display() const;	
	
	private : 
	
	int strenght;
	Weapon weaponTwo;
	
};

///////////////////////////////////////////////////////////////////
//non member read in / read out overloaded operators

//out
ostream& operator << (ostream& out, const Warrior& w1);

//in
istream& operator >> (istream& in, Warrior& w1);











#endif









