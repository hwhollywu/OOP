// ----------------------------------------------------------
// Main Program for Problem Set 2.					main.cpp
// Author: Hao Wu 
// Date: September 19, 2018.
// -----------------------------------------------------------

#include "tools.hpp"

void run(char* filename);

// ----------------------------------------------------------
// Main function. Print a header, execute a function, 
// and print a termination message. 

int main(int argc, char** argv) {
	banner();
	// only pass one command line argument
	if (argc == 2){
		run(argv[1]);
	}else{
		fatal("Wrong number of command line arguments!");
	}
	
	bye();
}

// ----------------------------------------------------------
//  This function read every integer or character 
//  from input file.

void run(char* filename) {
	// use x to store integers and ch to store characters
	// from the input stream.
	int x;
	char ch;
	// open a file 
	ifstream in(filename);
	if(!in){
		fatal("Failed to open the file! Please provide an existing filename.");
	}
	// read in each line
	do{
		in >> x;
		if (!in.fail()){
			// input is an integer
			cout << dec << x << endl;
		}else if (!in.eof()){
			in.clear();
			// input is a character
			in.get(ch);
			// convert ch to an unsigned char.
			unsigned char uch = ch;
			cout << "Skipping char: " << setfill(' ') << setw(3) << dec << (int) uch;
			cout << " 0x" << setfill('0') << setw(2) << hex << (int) uch;
			if (isprint(ch)){
				cout << " ’" << ch << "‘" << endl;
			}else{
				cout << endl;
			}
		}
	}while(in.good());

	if (!in.eof())  // Reading stopped before EOF
		fatal("Error reading input file %s", filename);

	cout << "Loop exit";

	in.close(); 
}

