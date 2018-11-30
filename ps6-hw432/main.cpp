// ----------------------------------------------------------
// Main Program for Problem Set 6.					main.cpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#include "tools.hpp"
#include "driver.hpp"


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
//  This function instantiates a Driver object 
// and call the Driver object’s start() function.

void run() {
    Driver d;      // Declare and initialize the driver class.
    d.start();    // Execute the start function.
}


