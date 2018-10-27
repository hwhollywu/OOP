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
	Agent* agents = new Agent[numAgents];
	int numOne;

public:
	//---------------------------------------- Constructors
    Simulator(int a, int o, unsigned int s){
    	numAgents = a;
    	numOne = o;
    	// set the seed for random function
    	cout << "srand(s) : " << s << endl;
    	srand (s);
    	for (int i = 0; i < numAgents; ++i){
    		if (i <= numOne){
    			agents[i] = Agent(1);
    		}else agents[i] = Agent(0);
    	}
    };  
	//---------------------------------------- Prototypes
	int run( int& rounds ); 

};

#endif 