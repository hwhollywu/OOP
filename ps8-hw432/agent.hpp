// ----------------------------------------------------------
// Abstract Agent class for Problem Set 8.			agent.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#pragma once

#include "tools.hpp"
#include "blockchain.hpp"

class Agent{

public:
	//------------------------------------ Constructors
	// virtual destructor
    virtual ~Agent(){}
	//--------------------------------- Virtual functions
	virtual void update(Blockchain m) =0;
	virtual Blockchain choice() const =0;
	virtual Blockchain extend() =0;
};

