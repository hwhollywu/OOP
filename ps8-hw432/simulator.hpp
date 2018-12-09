// ----------------------------------------------------------
// Simulator class for Problem Set 8.			simulator.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "population.hpp"


class Simulator{

private:
    Population* ppl;
    int maxRounds;
    double probExtend;

public:
	//---------------------------------------- Constructors
    Simulator(Population& p, int r, double extend);
    ~Simulator() = default;
    //------------------------------------ Inline functions 
    // return the number of rounds of simulation
    int numRounds()               { return maxRounds; }
	//---------------------------------------- Prototypes
	void run();  
};

#endif 