// ----------------------------------------------------------
// Driver class for Problem Set 6.					driver.cpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#include "driver.hpp"

// ----------------------------------------------------------
// Constructor
Driver::Driver(){
	// create the genesis block
 	Block genesis; 
 	// create a sp pointing to the genesis block
 	SPtr sp(&genesis);
 	// create the blockchain based on the sp
 	Blockchain bc0(sp);
 	for (int i = 0; i < 10; i++) {
 	 	bc[i] = bc0;
 	}
}

// ----------------------------------------------------------
//  This function is a driver program for blockchain.
void Driver::start(){
	char ch; // store single letter command
	cout << "Welcome to Blockchain World!" << endl;
	cout << "Type 'H' for user instructions." << endl; 
	for (;;) {
		cout << "Please enter your command: ";
		cin >> ch;
		ch = toupper(ch);

		switch(ch){
			// case 1: assign blockchains
			case 'A':
				char j;
				char k;
				cin >> j;
				cin >> k;
				if ('0' <= j && j <= '9' && '0' <= k && k <= '9' ){
					cout << "Assigning Block " << j << " to be equal to " <<"Block "<<k<<endl;
					bc[j-'0'] = bc[k-'0'];
					continue;
				}else{
					cout << "Block index should be within range [0-9]!" <<endl;
					break;
				}
			// case 2: extend blockchains
			case 'E':
				char i;
				cin >> i;
				if ('0' <= i && i <= '9'){
					cout << "Extending Block " << i <<endl;
					Blockchain bc_new = bc[i-'0'].extend();
					bc[i-'0'] = bc_new;
					continue;
				}else{
					cout << "Block index should be within range [0-9]!" <<endl;
					break;
				}
			// case 3: prints the blockchains in array bc[]
			case 'P':
				cout << "Printing out blockchains .." <<endl;
				for (int i=0; i<10; i++){
					cout << "Blockchain " << i << ": ";
					bc[i].print(cout);
					//cout << endl;
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
				cout << "------------------------------------" << endl;
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
