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
	int choice;
	
public:
	//--------------------------------------- Constructors
    Agent(int ch)	 					{choice = ch};   
	//------------------------------------ Inline functions	
	// update to the fickle agent by the message m.
	void update(int m)					{ choice = m; }
	// returns the agent’s current choice.
	int choice() const 					{ return choice; }
};

#endif 