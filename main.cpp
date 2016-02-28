//  **************************************************************************
//  Name: Louis Ciampanelli
//  Assignment #: #10 Using Classes with Inheritance and Polymorphism
//  File Name: functions.cpp
//  **************************************************************************//  Problem Statement **********************************************************

// Enter the problem statement as given


//  Data Requirements **********************************************************

// Enter the data variables and formulas required for the problem
// Indicate names, datatypes and initial values

//      Input
//      Output
//      Processing
//      Formulas


//  Algorithm Design ***********************************************************

// Enter the algorithm in step-by-step outline format
// For example:
/*
 1. Display description of game
 
 2. Prompt user for hhow many players they would like
 2.1. validate
 3. use a function to get user input for players
 3.1 return the player objects into a vector
 4. use a function to modify the players levels and weapon levels
 4.1. add random numbers between -15 and 15 to the levels and weapon levels
 4.1. run a loop that repeats this 25 times
 5. check for the following:
 5.1. if weapon level > 200, + 40 to player level
 5.2. if weapon level < 0 player status = false
 5.3. if player level > 200 that player is the winner and the game is over
 6. display results
 6.1 display winner
 6.2 display losers
 */

//  Testing Specifications *****************************************************

// Specify tests needed to verify that program works correctly



#include "weapons.h"
#include "functions.h"
#include "player.h"
#include "wizard.h"
#include "warrior.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>


using namespace std; 

//  Function Prototypes ********************************************************


//  main function **************************************************************

int main ()
{
    srand (int(time (0)));	// seed random number
    
    //Warrior *myWarrior;
    //myWarrior = new Warrior;

    //cin >> *myWarrior;
    //cout << *myWarrior;
    
    // All variable declarations go here
	
	int playerNum, max, playerWithMax; // playerType;
	vector <Warrior> warriors;
	//vector <Wizard> wizards;
    
    //Executable statements following algorithm go here
	
    // displays description of game
	description();
	
    //prompts the user for how many players they would like
	playerNum = howMany();
	if (playerNum == 0)			// if they respond 0 - game over
	{
		return 0;
	}
	
    //loop that gets info for the objects in the loop
	for (int i = 0; i < playerNum; i++)
	{
            Warrior myWarrior;
            cin >> myWarrior;
			
            warriors.push_back(myWarrior);		
	}
	
	cout << endl << endl;		//makes ui look better
	
    //loop that runs 25 times and modifies wizard/warrior data
	for (int i = 0; i < 25; i++)
	{
		//checks to see if the players status is true, then modifies
		for (int j = 0; j < warriors.size(); j++)
		{
			if (warriors[j].getStatus() == true)
			{
                int rand = randomGenerator(0, 15);
                if (rand % 2 == 0)
                    warriors[j] += rand;
                else
                    warriors[j] -= rand;

               // players[j]->modify();
			}
		}
        
        // sees if the player level or the weapon level is less then 0
        //if so it chnages the player status to 0
		for (int i = 0; i < warriors.size(); i++)
		{	
			int p, w;
			p = warriors[i].getLevel();
			//w = players[i]->getWeaponLevel();
            
			if (p < 0 || w < 0)
			{
				warriors[i].setStatus(false);
			}
		}
        
        //if a player has more then 200 points player wins/game over
		for (int i = 0; i < warriors.size(); i++)
		{
			if (warriors[i].getStatus() == true) 
			{
				int n;
				n = warriors[i].getLevel();
                if (n > 200)
                {
                    cout << "The Winner is: " << endl << endl;
					
                    cout << warriors[i];
                    playerWithMax = i;
                    for (int i = 0; i < warriors.size(); i++)
                    {
                        if (i != playerWithMax)	//displays losers
                        {
                            cout << "Losers: " << endl << endl;
							cout << warriors[i];
                        }
                    }
                }
			}
		}
	}
    //set the max and the player with the max to 0
    max = warriors[0].getLevel();
    playerWithMax = 0;
	
    // finds out which player has the highest score
	for (int i = 0; i < warriors.size(); i++)
    {
        if (warriors[i].getLevel() > max)
        {
            max = warriors[i].getLevel();
            playerWithMax = i;
        }	
        
    }
    
    // displays the player with the highest score
	cout << left;
	cout << setw(20) << "The Winner is:" << endl;
	cout << warriors[playerWithMax];
	
    //displays the losers
	if (playerNum >= 1)
	{
		cout << "Losers:" << endl << endl;
		for (int i = 0; i < warriors.size(); i++)
		{
			if (i != playerWithMax)
			{
				cout << warriors[i];
			}
		}
	}
	
	
    // End of program statements
	cout << "Please press enter once or twice to continue...";
	cin.ignore().get();    			// hold console window open
	return EXIT_SUCCESS;           	// successful termination
    
}
//  end main() *****************************************************************


//  Function Implementations ***************************************************

