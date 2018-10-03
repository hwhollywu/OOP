// ----------------------------------------------------------
// Game class for Problem Set 3.					game.cpp
// Author: Hao Wu 
// Date: September 30, 2018.
// -----------------------------------------------------------

#include "game.hpp"


// ----------------------------------------------------------
//  This function starts the think-a-dot game. It creates a 
//  think-a-dot object and asks the user for commands.
void Game::
play(){
	char ch; // store single letter command
	ThinkaDot tad;

	cout << "Welcome to the Think-a-Dot Game!" << endl;
	cout << "Type 'H' for user instructions." << endl; 
	while (1) {
		cout << "Please enter your command: ";
		cin >> ch;
		ch = toupper(ch);

		// case 1: simulate the action of the machine
		if (ch == 'A' || ch == 'B' || ch == 'C'){

			tad.play(ch);
			continue;
		}
		// case 2: reset all points to be left or right 
		if (ch == 'L' || ch == 'R'){
			tad.reset(ch);
			continue;
		}
		// case 3: prints the state of the machine
		if (ch == 'P'){
			tad.print(cout);
			continue;
		}
		// case 4: prints a brief version of these instructions
		if (ch == 'H'){
			cout << "- User Instruction for Think-a-Dot Game -" << endl;
			cout << "Valid inputs include the following single letters: " << endl;
			cout << "A/B/C: to drop the ball in respective hole; " << endl;
			cout << "L/R: to reset all points to the left / right; " << endl;
			cout << "P: to print the current state of the machine;" << endl;
			cout << "Q: to quit the game;" << endl;
			continue;
		}
		// case 5: exits the program.
		if (ch == 'Q'){
			break;
		} 

		// Ask user for new command, if the input is invalid 
		else{
			cin.clear();
			cout << "The input is not valid! Type 'H' for help." << endl;
		}
	}

	cout << "Program exit.";

}