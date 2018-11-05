// ----------------------------------------------------------
// Agent class for Problem Set 5.					agent.hpp
// Author: Hao Wu 
// Date: Nov 3, 2018.
// -----------------------------------------------------------

#ifndef AGENT_HPP
#define AGENT_HPP

#include "tools.hpp"

class Agent{

public:
	//------------------------------------ Constructors
	Agent() = default; // need constructor??
	// virtual destructor
    virtual ~Agent(){
    	cout << "Agent Destructor" << endl; //?
    }

	//--------------------------------- Virtual functions
	virtual void update(int m);
	virtual int choice() const = 0;
};

#endif 