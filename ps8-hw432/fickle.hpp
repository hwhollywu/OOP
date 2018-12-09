// ----------------------------------------------------------
// Fickle class for Problem Set 8.					fickle.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#ifndef FICKLE_HPP
#define FICKLE_HPP

#include "agentbase.hpp"

class Fickle: public AgentBase{

public:
	//--------------------------------------- Constructors
    Fickle() = default;
    ~Fickle() = default;
    Fickle(Blockchain c){ ch = c; }
    // Default copy constructor 
    Fickle( const Fickle& ) 		  		 =default;    
    // Default copy assignment
    Fickle& operator=( const Fickle& ) 	 	 =default;    
    // Default move constructor
    Fickle( Fickle&& )						 =default;
    // move assignement
    Fickle& operator=( Fickle&& other){ 
    	ch = other.ch;
    	return *this;
    }
      
};

#endif 