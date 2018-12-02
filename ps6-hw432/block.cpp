// ----------------------------------------------------------
// Block class for Problem Set 6.					block.cpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#include "block.hpp"

//-----------------------------------------------------------------------
// Prints the current block information
ostream& Block::
print(ostream& out) const {
	out << " [" << level <<","<< serialNo <<"]";
	return out;
}

//-----------------------------------------------------------------------
// Recursively prints the block chain information from the head
void Block::
printChain() const {
	Block* prev = sp.getTarget();
	// recursive case
	if (prev != nullptr){
		prev->printChain();
	}
	// base case
	print(cout);
}