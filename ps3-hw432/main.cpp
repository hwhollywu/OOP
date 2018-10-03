// ----------------------------------------------------------
// Main Program for Problem Set 3.					main.cpp
// Author: Hao Wu 
// Date: September 30, 2018.
// -----------------------------------------------------------

#include "tools.hpp"
#include "game.hpp"


void run();

// ----------------------------------------------------------
// Main function. Print a header, execute a function, 
// and print a termination message. 

int main(int argc, char* argv[]) {
	banner();
	run();
	bye();
}

// ----------------------------------------------------------
//  This function instantiates a Game object 
// and call the Game object’s play() function.

void run() {
    Game g;      // Declare and initialize the Game class.
    g.play();    // Execute the game function.
}


