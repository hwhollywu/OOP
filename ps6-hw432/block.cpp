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
	out << " [" << blkLevel() <<","<<serialId()<<"] ";
	return out;
}

//-----------------------------------------------------------------------
// Recursively prints the block chain information from the head
ostream& Block::
printChain(ostream& out) const {
	Block* prev = p.getTarget();
	// base case
	if (level == 0){
		return print(out);
	}
	// recursive case
	return prev->printChain(out);
}