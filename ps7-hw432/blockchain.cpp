// ----------------------------------------------------------
// Blockchain class for Problem Set 7.			blockchain.cpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#include "blockchain.hpp"

// ----------------------------------------------------------
// This function returns a new blockchain created by extending 
// the current blockchain. The new chain should be stack-allocated 
// and returned by value.
Blockchain Blockchain::extend(){
	// create a new block using the copy of smart pointer
	// malloc space for the new block
	Block* b = new Block(sp);
	// return the new blockchain
	return Blockchain(b);
}

//-----------------------------------------------------------------------
// Prints the blocks that comprise a blockchain in order of increasing level.
ostream& Blockchain::
print(ostream& out) const {
	Block* prev = sp.getTarget();
	prev->printChain();
	out << endl;
	return out;
}

//-----------------------------------------------------------------------
// Operator == checks if two blockchains are equivalent.
bool Blockchain::operator==(Blockchain &bc2){
	// check if the length and each level of blockchains are equal 
	if (length() != bc2.length()) return false;
	Block* tail1 = tail();
	Block* tail2 = bc2.tail();
	if(tail1 -> serialId() != tail2 -> serialId()) return false;
	else return true; 
};
