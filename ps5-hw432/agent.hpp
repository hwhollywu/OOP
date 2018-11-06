// ----------------------------------------------------------
// Abstract Agent class for Problem Set 5.			agent.hpp
// Author: Hao Wu 
// Date: Nov 3, 2018.
// -----------------------------------------------------------

#pragma once

#include "tools.hpp"

class Agent{

public:
	//------------------------------------ Constructors
	// virtual destructor
    virtual ~Agent(){}
	//--------------------------------- Virtual functions
	virtual void update(int m) =0;
	virtual int choice() const =0;
};

