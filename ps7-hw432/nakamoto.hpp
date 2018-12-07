// ----------------------------------------------------------
// Nakamoto class for Problem Set 7.			agentbase.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#ifndef NAKAMOTO_HPP
#define NAKAMOTO_HPP

#include "agentbase.hpp"

class Nakamoto: public AgentBase{

public:
	//--------------------------------------- Constructors
    Nakamoto() = default;
    ~Nakamoto() = default;
    Nakamoto(Blockchain c){ ch = c; }
    // Default copy constructor 
    Nakamoto( const Fickle& ) 		  		 =default;    
    // Default copy assignment
    Nakamoto& operator=( const Fickle& ) 	 =default;    
    // Default move constructor
    Nakamoto( Fickle&& )					 =default;
    // move assignement
    Nakamoto& operator=( Fickle&& other){ 
    	ch = other.ch;
    	return *this;
    }
    //------------------------------------ Inline functions	
	// Overwrite the update function
	void update(Blockchain m){
		// only update ch if m is longer than ch.
		if (m.length() > ch.length()){
			ch = m;
		}
	 }


};

#endif 