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
	Blockchain() = default;
    ~Blockchain() = default;
    // Default copy constructor
    Blockchain( const Blockchain& ) =default; 
    // Default copy assignment   
    Blockchain& operator=( const Blockchain& ) =default;    
    // Default move constructor
    Blockchain( Blockchain&& )=default;
    // Default move assignement
    Blockchain& operator=( Blockchain&& other)=default;
	//---------------------------------- Function Prototypes
    unsigned length(); 
    block* tail();
	Blockchain extend();
	ostream& print(ostream& out) const;
};

inline ostream& operator<<( ostream& out, const Blockchain& bc ) {
    return bc.print( out );
}

inline Blockchain operator==(Blockchain bc1, Blockchain bc2){
	return bc1 == bc2; 
};


#endif