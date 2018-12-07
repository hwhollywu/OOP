// ----------------------------------------------------------
// Blockchain class for Problem Set 7.			blockchain.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------


#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "SPtr.hpp"
#include "block.hpp"

class Blockchain{

private:
	SPtr sp;

public:
	//---------------------------------------- Constructors
    // Constructors
    Blockchain() =default;
	Blockchain(Block* b) : sp( SPtr(b) ){}
    // Destructor
    ~Blockchain()=default;
    // copy constructor
    Blockchain( const Blockchain& )=default; 
    // copy assignment   
    Blockchain& operator=( const Blockchain& )=default;    
    // Default move constructor
    Blockchain( Blockchain&& )=default;
    // Default move assignement
    Blockchain& operator=( Blockchain&& other)=default;
    //---------------------------------- Inline functions
    // returns a regular pointer to the last (most recent) block
    Block* tail() {return sp.getTarget();}
    // returns the length of current blockchain.
    unsigned length(){return sp.getTarget()->blkLevel(); } 
	//---------------------------------- Function Prototypes
	Blockchain extend();
	ostream& print(ostream& out) const;
};


inline ostream& operator<<( ostream& out, const Blockchain& bc ) {
    return bc.print( out );
} 

#endif