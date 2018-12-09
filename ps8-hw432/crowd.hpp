// ----------------------------------------------------------
// Crowd class for Problem Set 8.					crowd.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#ifndef CROWD_HPP
#define CROWD_HPP

#include "agentbase.hpp"

class Crowd : public AgentBase{

private:
	Blockchain st; 
	
public:
	//--------------------------------------- Constructors
    Crowd() = default;
    ~Crowd() = default;
    Crowd(Blockchain c){ 
    	ch = c; 
    	st = c;
    }
    // Default copy constructor 
    Crowd( const Crowd& ) 		  	 	  	 =default;    
    // Default copy assignment
    Crowd& operator=( const Crowd& )		 =default;    
    // Default move constructor
    Crowd( Crowd&& )                		 =default;    
    // move assignement
    Crowd& operator=( Crowd&& other){ 
    	ch = other.ch;
    	st = other.st;
    	return *this;
    }
    
	//------------------------------------ Inline functions	
	// Overwrite the update function
	void update(Blockchain m){
		if (st == m){
            ch = m;
		} else {
			st = m;
		}
	 }
	// returns the current state.
	Blockchain state() const 					{ return st; }
};

#endif 