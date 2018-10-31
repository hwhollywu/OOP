// ----------------------------------------------------------
// Agent class for Problem Set 4.					agent.hpp
// Author: Hao Wu 
// Date: October 26, 2018.
// -----------------------------------------------------------

#ifndef AGENT_HPP
#define AGENT_HPP

#include "tools.hpp"

class Agent{

private:
	int ch;
	
public:
	//--------------------------------------- Constructors
    Agent() = default;
    Agent(int c){ ch = c; }
    // move assignement
    Agent& operator=( Agent&& other){ 
    	ch = other.ch;
    	return *this;
    }
      
	//------------------------------------ Inline functions	
	// update to the fickle agent by the message m.
	void update(int m)					{ ch = m; }
	// returns the agent’s current choice.
	int choice() const 					{ return ch; }
};

#endif 