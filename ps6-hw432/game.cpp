// ----------------------------------------------------------
// Game class for Problem Set 6.					game.cpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#include "game.hpp"

// ----------------------------------------------------------
//  This function is a driver program for blockchain. It creates  
//  blockchain objects  with genesis blocks.
void Game::
play(){
	char ch; // store single letter command
	// create an array bc of 10 blockchains.
	Blockchain bc [10];
	for (int i=0; i<10; i++){
		SPtr sp = SPtr();
		Block b = block(sp); // genesis block
		SPtr sp1 = SPtr(b);
		bc[i] = Blockchain(sp1);
	}

	cout << "Welcome to Blockchain World!" << endl;
	cout << "Type 'H' for user instructions." << endl; 
	for (;;) {
		cout << "Please enter your command: ";
		cin >> ch;
		ch = toupper(ch);

		switch(ch){
			// case 1: assign blockchains
			case 'A':
				char i;
				char k;
				cin >> i;
				cin >> k;
				bc[i]==bc[k];
				continue;
			// case 2: extend blockchains
			case 'E':
				char j;
				cin >> j;
				bc[j].extend();
				continue;
			// case 3: prints the state of the machine
			case 'P':
				for (int i=0; i<bc.size(); ++i){
					bc[i].print();
				}
				continue;
			// case 4: prints a brief version of these instructions
			case 'H':
				cout << "- User Instruction for Blockchain -" << endl;
				cout << "Valid inputs include the following single letters: " << endl;
				cout << "Ajk: Assign blockchain j to be equal to blockchain k; " << endl;
				cout << "Ej: Extends blockchain j; " << endl;
				cout << "P: Prints the blockchains in array, one per line;" << endl;
				cout << "Q: to quit the game;" << endl;
				continue;
			// case 5: exits the program.
			case 'Q': 
				cout << "Program exit.";
				return;
			default: 
			// Ask user for new command, if the input is invalid 
				cin.clear();
				cout << "The input is not valid! Type 'H' for help." << endl;
		}

	}



}