// ----------------------------------------------------------
// Blockchain class for Problem Set 6.			blockchain.cpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#include "blockchain.hpp"


// ----------------------------------------------------------
// This function returns a new blockchain created by extending 
// the current blockchain. The new chain should be stack-allocated 
// and returned by value.
Blockchain Blockchain::extend(){
	// create a new block using the current smart pointer
	if (p.empty()){
		cout << "p is empty!" << endl;
	}else {
		cout << "Pointer is " << p << endl;
	}
	Block b = Block(p, length()+1);
	p = SPtr(&b);
	cout << "Pointer is" << p << endl;
	return *this;
}

//-----------------------------------------------------------------------
// Prints the blocks that comprise a blockchain in order of increasing level.
std::ostream& Blockchain::
print(ostream& out) const {
	SPtr t = p;
	// TO-DO: reversely print out
	while(t.get() != nullptr){
		out << " [" << t.get()->blkLevel() <<","<<t.get()->serialId()<<"]";
		t = t.get()->last();
	}
	return out;
}
//-----------------------------------------------------------------------
// Operator == checks if two blockchains are equivalent.
bool Blockchain::operator==(Blockchain &bc2){
	// check if the length and each level of blockchains are equal 
	if (length() != bc2.length()) return false;
	else{ 
		Block* tail1 = tail();
		Block* tail2 = bc2.tail();
		while(tail1 != nullptr && tail2 != nullptr){
			if(tail1->blkLevel() != tail2->blkLevel()) return false;
			tail1 = tail1->last();
			tail2 = tail2->last();
		}
		if (tail1 != nullptr || tail2 != nullptr) return false;
	}
	return true; 
};

