// ----------------------------------------------------------
// Blockchain class for Problem Set 6.			blockchain.cpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#include "blockchain.hpp"

//------------------------------------------------------------------------------
// constructor
Blockchain::Blockchain(SPtr sp) : p(sp) {
    cout << "  SPtr constructor called for Blockchain " << endl;
}

//------------------------------------------------------------------------------
// Destructor
Blockchain::~Blockchain() {
    cout << "  Destructor called for Blockchain "<< endl;
    p.reset();
}

// ----------------------------------------------------------
// This function returns a new blockchain created by extending 
// the current blockchain. The new chain should be stack-allocated 
// and returned by value.
Blockchain Blockchain::extend(){
	// create a new block using the current smart pointer
	Block b = Block(p);
	SPtr sp = SPtr(b);
	p = sp;
}

//-----------------------------------------------------------------------
// Prints the blocks that comprise a blockchain in order of increasing level.
std::ostream& Blockchain::
print(ostream& out) const {
	SPtr t = p;
	// TO-DO: reversely print out
	while(t.get() != nullptr){
		out << " [" << t.get().blkLevel() <<","<<t.get().serialId()<<"]";
		t = t.get().last();
	}
	return out;
}
//-----------------------------------------------------------------------
// Operator == checks if two blockchains are equivalent.
bool Blockchain::operator==(Blockchain bc1, Blockchain bc2){
	// check if the length and each level of blockchains are equal 
	if (bc1.length() != bc2.length()) return false;
	else{ 
		block* tail1 = bc1.tail();
		block* tail2 = bc2.tail();
		while(tail1 != nullptr && tail2 != nullptr){
			if(tail1.blkLevel() != tail2.blkLevel()) return false;
			tail1 = tail1.last();
			tail2 = tail2.last();
		}
		if (tail1 != nullptr || tail2 != nullptr) return false;
	}
	return true; 
};

