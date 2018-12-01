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
	out << " [" << blkLevel() <<","<<serialId()<<"]";
	return out;
}

//-----------------------------------------------------------------------
// Recursively prints the block chain information from the head
void Block::
printChain(ostream& out) const {
	// base case
	if (level == 0){
		print(out);
		return;
	}
	// recursive case
	Block* prev = p.getTarget();
	//out << "recursive case"<< " *prev: " << *prev << "level: " << level <<endl;
	prev->printChain(out);
	print(out);
}