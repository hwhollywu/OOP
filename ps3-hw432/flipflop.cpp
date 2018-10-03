// ----------------------------------------------------------
// Flip Flop Model for Problem Set 3.			flipflop.cpp
// Author: Hao Wu 
// Date: September 30, 2018.
// -----------------------------------------------------------

#include "flipflop.hpp"


//------------------------------------------------------------
// Print the status from flip-flop
void FlipFlop::print(ostream& out) const {
	if (status == LEFT){
		out << 'L';
	}else{
		out << 'R';
	}
}

//------------------------------------------------------------
// Flips the state from “left” to “right” or vice versa 
// and returns the new status of the flip-flop
char FlipFlop::flip(){
	if (status == LEFT){
		status = RIGHT;
		return 'R';
	}else{
		status = LEFT;
		return 'L';
	}
}

//------------------------------------------------------------
// Set the flip-flop status to RIGHT or LEFT by giving character 
void FlipFlop::setStatus(char ch){
	if (ch == 'L'){
		status = LEFT;
	}else if (ch == 'R'){
		status = RIGHT;
	}else{
		fatal("An invalid status was entered!");
	}
}


