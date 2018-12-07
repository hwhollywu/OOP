// ----------------------------------------------------------
// AgentBase class for Problem Set 7.			agentbase.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#ifndef AGENTBASE_HPP
#define AGENTBASE_HPP

#include "agent.hpp"

class AgentBase: public Agent{

public:
	Blockchain ch;
	//------------------------------------ Inline functions	
	// update to the agent by the choice m.
	virtual void update(Blockchain m)			{ ch = m; }
	// returns the current choice.
	virtual Blockchain choice() const 			{ return ch; }
	// extend the blockchain
	virtual void extend() 						{ch.extend();}
};


#endif 