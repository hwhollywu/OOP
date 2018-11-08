// ----------------------------------------------------------
// Simulator class for Problem Set 5.			simulator.hpp
// Author: Hao Wu 
// Date: Nov 3, 2018.
// -----------------------------------------------------------

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "population.hpp"


class Simulator{

private:
	int rounds;
    Population* ppl;

public:
	//---------------------------------------- Constructors
    Simulator(Population& p);
    ~Simulator() = default;
    //------------------------------------ Inline functions 
    // return the number of rounds of simulation
    int numRounds()               { return rounds; }
    // return the consensus value
    int consensusValue()          { return ppl->consensusValue(); }
	//---------------------------------------- Prototypes
	void run();  
};

#endif 