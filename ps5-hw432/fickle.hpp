// ----------------------------------------------------------
// Fickle class for Problem Set 5.					fickle.hpp
// Author: Hao Wu 
// Date: Nov 3, 2018.
// -----------------------------------------------------------

#ifndef FICKLE_HPP
#define FICKLE_HPP

#include "agent.hpp"


class Fickle: public Agent{

private:
	int ch;
	
public:
	//--------------------------------------- Constructors
    Fickle() = default;
    Fickle(int c){ ch = c; }
    // move assignement
    Fickle& operator=( Fickle&& other){ 
    	ch = other.ch;
    	return *this;
    }
      
	//------------------------------------ Inline functions	
	// update to the fickle agent by the message m.
	virtual void update(int m)					{ ch = m; }
	// returns the current choice.
	virtual int choice() const 					{ return ch; }
};

#endif 