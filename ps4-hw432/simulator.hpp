// ----------------------------------------------------------
// Simulator class for Problem Set 4.			simulator.hpp
// Author: Hao Wu 
// Date: October 26, 2018.
// -----------------------------------------------------------

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "agent.hpp"


class Simulator{

private:
	int numAgents;
	int numOne;
    Agent* agents;

public:
	//---------------------------------------- Constructors
    Simulator(int a, int o, unsigned int s);
    // destructor 
    ~Simulator() {
        delete[] agents;
    }
	//---------------------------------------- Prototypes
	int run( int& rounds ); 

};

#endif 