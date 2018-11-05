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
	int numRounds;
    Population* ppl;

public:
	//---------------------------------------- Constructors
    Simulator(Population& p);
    //------------------------------------ Inline functions 
    // return the number of rounds of simulation
    int numRounds()               { return numRounds; }
    // return the consensus value
    int consensusValue()          { return ppl.consensusValue(); }
	//---------------------------------------- Prototypes
	void run();  

};


inline ostream& operator<<( ostream& out, const Simulator& s ) {
    return s.print( out );
}

#endif 