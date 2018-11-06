// ----------------------------------------------------------
// Crowd class for Problem Set 5.					crowd.hpp
// Author: Hao Wu 
// Date: Nov 3, 2018.
// -----------------------------------------------------------

#ifndef CROWD_HPP
#define CROWD_HPP

#include "agent.hpp"

class Crowd : public Agent{

private:
	int ch;
	int st; 
	
public:
	//--------------------------------------- Constructors
    Crowd() = default;
    Crowd(int c){ ch = c; }
    // copy constructor 
    Crowd( const Crowd& ) 		   =default;    
    // copy assignment
    Crowd& operator=( const Crowd& ) =default;    
    // Default move constructor
    Crowd( Crowd&& )                 =default;    
    // move assignement
    Crowd& operator=( Crowd&& other){ 
    	ch = other.ch;
    	st = other.st;
    	return *this;
    }
    
	//------------------------------------ Inline functions	
	// update to the crowd agent by the message m.
	virtual void update(int m){
		if (st != m){
			st = m;
		} else {
			ch = m;
		}
	 }
	// returns the current choice.
	virtual int choice() const 			{ return ch; }
	// returns the current state.
	int state() const 					{ return st; }
	
};

#endif 