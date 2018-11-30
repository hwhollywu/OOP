// ----------------------------------------------------------
// Blockchain class for Problem Set 6.			blockchain.hpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------


#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "SPtr.hpp"
#include "block.hpp"

class Blockchain{

private:
	SPtr p;

public:
	//---------------------------------------- Constructors
    // Constructors
    Blockchain() = default;
	Blockchain(SPtr sp) : p(sp){};
    ~Blockchain() =default;
    // copy constructor
    Blockchain( const Blockchain& bc ); 
    // copy assignment   
    Blockchain& operator=( const Blockchain& bc );    
    // Default move constructor
    Blockchain( Blockchain&& )=default;
    // Default move assignement
    Blockchain& operator=( Blockchain&& other)=default;
    //---------------------------------- Inline functions
    // returns a regular pointer to the last (most recent) block
    Block* tail() {return p.getTarget();}
    // returns the length of current blockchain.
    unsigned length(){return p.getTarget()->blkLevel(); } 
	//---------------------------------- Function Prototypes
	Blockchain extend();
	ostream& print(ostream& out) const;
	// bool operator==(Blockchain &bc2);
};


inline ostream& operator<<( ostream& out, const Blockchain& bc ) {
    return bc.print( out );
} 

#endif