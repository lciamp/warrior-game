//  **************************************************************************
//  Name: Louis Ciampanelli
//  Assignment #: #10 Using Classes with Inheritance and Polymorphism
//  File Name: functions.cpp
//  **************************************************************************#ifndef WARRIOR_H
//  Compiler directives ********************************************************



#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "wizard.h"
#include "functions.h" 

using namespace std;

	//constructor without parameters
Wizard::Wizard()
	:Player()
{
	magic = 25;
	weaponTwo = Weapon(4,25);
}

	//constructor with parameters
Wizard::Wizard(string n, int l, int wepType, int wepLevel, int m)
	:Player(n, l, wepType, wepLevel)
{
	weaponTwo = Weapon(wepType, wepLevel);
	magic = m;
}

	//prompts user and reads in all data for wizard
void Wizard::read()
{
	int m, type, level;
	Player::read();
	cout << "Select a level for your magic(0-200): " << endl;
	cin >> m;
	while (m < 0 || m > 200)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> m;
	}
	magic = m;
	
	cout << "Please select a weapon: " << endl
	<< "5 - Wand" << endl 
	<< "6 - Staff" << endl
	<< "7 - Fire Stick" << endl;
	cin >> type;
	while (type < 5 || type > 7)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> type;
	}
	weaponTwo.setType(--type);
	
	cout << "Please enter a level for your weapon(0-200): " << endl;
	cin >> level;
	while (level < 0 || level > 200)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> level;
	}
	weaponTwo.setLevel(level);
}

	//set magic
void Wizard::setPower(int m)
{
	magic = m;
}

	//set weapon
void Wizard::setWeapon(int w)
{
	weaponTwo.setType(w);
}

//get functions

	//get magic
int Wizard::getPower() const
{
	return magic;
}

	//get weapon 
int Wizard::getWeapon() const
{
	return weaponTwo.getType();
}

    //add to magic
void Wizard::operator += (const int num)
{
    int temp = getPower() + num;
    setPower(temp);
}

    //subtract form magic
void Wizard::operator -= (const int num)
{
    int temp = getPower() - num;
    setPower(temp);
}


	//modify data
void Wizard::modify()
{
    int m, playerLevel;
	
	//randomly modify the weapon level
	weaponTwo.modify();
	
	//if the magic is > 200, then add 40 to the player level
	m = getPower();
	playerLevel = getLevel();
	if (m > 200) 
	{
		setLevel(playerLevel += 40);
	}
	if (getLevel() <= 0 || getWeaponLevel() <= 0 || magic <= 0)
	{
		setStatus(false);
	}
	
}	

	//displays all data for wizard
void Wizard::display() const
{
	cout << left;
	cout << setw(20) << "Player Type:" << "Wizard" << endl;
	Player::display();
	cout << setw(20) << "Magic Level: " << magic << endl;
	weaponTwo.display();
	cout << endl;
}



//////////////////////////////////////////////////////////////////////
//non member functions

//out
ostream& operator << (ostream& out, const Wizard& w1)
{
    string choice[7] = {"Sword", "Axe", "Bow", "Knife", 
		"Wand", "Staff", "Fire Stick"};
    
    out << left;
    out << setw(20) << "Player Type:" << "Wizard" << endl;
    out << setw(20) << "Wizard Name:" << w1.getName() << endl;
    out << setw(20) << "Wizard Level:" << w1.getLevel() << endl;
    out << setw(20) << "Wizard Magic:" << w1.getPower() << endl;
    out << setw(20) << "Weapon Type: " << choice[w1.getWeaponType()] << endl;
    out << setw(20) << "Weapon Level: "  << w1.getWeaponLevel() << endl;
    
    return out;
    
}


istream& operator >> (istream& in, Wizard& w1)
{

    int level, magic, wepLevel, wepType;
    string fName, lName, name;
    cout << "Please enter a first name for your Wizard: " << endl;
    in >> fName;
    cout << "Please enter a last name for your Wizard: " << endl;
    in >> lName;
    name = fName + " " + lName;
    w1.setName(name);
    cout << "Please enter a level for your Wizard: " << endl;
    in >> level;
    w1.setLevel(level);
    cout << "Please enter a magic level for your Wizard: " << endl;
    in >> magic;
    w1.setPower(magic);
    cout << "Please select a weapon: " << endl
	<< "5 - Wand" << endl 
	<< "6 - Staff" << endl
	<< "7 - Fire Stick" << endl;
	in >> wepType;
	while (wepType < 5 || wepType > 7)
	{
		cout << "Invalid number, Try Again: " << endl;
		in >> wepType;
	}
	w1.setWeaponType(wepType-1);
    cout << "Please enter a weapon level: " << endl;
    in >> wepLevel;
    w1.setWeaponLevel(wepLevel);
    return in;
    
}


