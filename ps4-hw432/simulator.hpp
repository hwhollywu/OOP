// ----------------------------------------------------------
// Simulator class for Problem Set 4.			simulator.hpp
// Author: Hao Wu 
// Date: October 26, 2018.
// -----------------------------------------------------------

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

class Simulator{

private:
	int numAgents;
	Agent* agents = new Agent[numAgents];
	int numOne;

public:
	//---------------------------------------- Constructors
	Simulator(){
		numAgents = 0;
		numOne = 1;
		srand(time[0]);
	}; // default constructor 
	
    Simulator(int a, int o, unsigned int s){
    	numAgents = a;
    	numOne = o;
    	// set the seed for random function
    	srand (s);
    };  
	//---------------------------------------- Prototypes
	int run( int& rounds ); 

};

#endif 