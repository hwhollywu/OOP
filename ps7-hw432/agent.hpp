// ----------------------------------------------------------
// Abstract Agent class for Problem Set 7.			agent.hpp
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
	virtual void update(int m) =0;
	virtual Blockchain choice() const =0;
	virtual void extend() =0;
};

