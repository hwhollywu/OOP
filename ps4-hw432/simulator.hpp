// ----------------------------------------------------------
// Simulator class for Problem Set 4.			simulator.hpp
// Author: Hao Wu 
// Date: October 26, 2018.
// -----------------------------------------------------------

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "agent.hpp"

#define INIT_AGENTS 10 

class Simulator{

private:
	int numAgents = INIT_AGENTS;
	Agent** agents;
	int numOne;

public:
	//---------------------------------------- Constructors
    Simulator(int a, int o, unsigned int s);
	//---------------------------------------- Prototypes
	int run( int& rounds ); 

};

#endif 