// ----------------------------------------------------------
// Blockchain class for Problem Set 6.			blockchain.cpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#include "blockchain.hpp"

// ----------------------------------------------------------
// This function returns the length of current blockchain.
unsigned Blockchain::length(){

 }

// ----------------------------------------------------------
// This function returns a regular pointer to the last block
block* Blockchain::tail(){
	return p.get();
}

// ----------------------------------------------------------
// This function returns a new blockchain created by extending 
// the current blockchain. The new chain should be stack-allocated 
// and returned by value.
Blockchain Blockchain::extend(){
	void SPtr::reset() {


}

//-----------------------------------------------------------------------
// Prints the blocks that comprise a blockchain in order of increasing level.
std::ostream& Blockchain::
print(ostream& out) const {
	out << "Population statistics:" << endl;
	out << "   numFickle:    "<< numFickle << endl;
	out << "    numCrowd:    "<< (numAgents - numFickle) << endl;
	out << "     numOnes:    "<< numOne << endl;
	return out;
}