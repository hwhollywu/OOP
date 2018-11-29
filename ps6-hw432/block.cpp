// ----------------------------------------------------------
// Block class for Problem Set 6.					block.cpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#include "block.hpp"

//-----------------------------------------------------------------------
// Prints the current block information
std::ostream& Block::
print(ostream& out) const {
	out << " [" << blkLevel() <<","<<serialId()<<"]";
	return out;
}

//-----------------------------------------------------------------------
// Recursively prints the block chain information from the head
void Block::printChain() {
	// base case
	if (p.get() == nullptr){
		print(cout);
		return;
	}
	// recursive case		
	Block* b = p.get();
	cout << " recursive b! " << endl;
	b->print(cout);
	// b->printChain();
}