// ----------------------------------------------------------
// Blockchain class for Problem Set 6.			blockchain.hpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------


#ifndef BLOCKCHIAN_HPP
#define BLOCKCHAIN_HPP

#include "SPtr.hpp"

class Blockchain{

private:
	SPtr p;

public:
	//---------------------------------------- Constructors
	Blockchain(SPtr p);
    ~Blockchain() = default;
    // Default copy constructor
    Blockchain( const Blockchain& ) =default; 
    // Default copy assignment   
    Blockchain& operator=( const Blockchain& ) =default;    
    // Default move constructor
    Blockchain( Blockchain&& )=default;
    // Default move assignement
    Blockchain& operator=( Blockchain&& other)=default;
    //---------------------------------- Inline functions
    // returns a regular pointer to the last (most recent) block
    block* tail(){return p.get();}
    // returns the length of current blockchain.
    unsigned length(){return p.get().blkLevel(); } 
	//---------------------------------- Function Prototypes
	Blockchain extend();
	ostream& print(ostream& out) const;
};

inline ostream& operator<<( ostream& out, const Blockchain& bc ) {
    return bc.print( out );
}

inline bool operator==(Blockchain bc1, Blockchain bc2){
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


#endif