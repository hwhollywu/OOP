// ----------------------------------------------------------
// Population class for Problem Set 5.			population.hpp
// Author: Hao Wu 
// Date: Nov 3, 2018.
// -----------------------------------------------------------

// manage populations with two kinds of agents 
// as well as two possible initial values.

#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "fickle.hpp"
#include "crowd.hpp"

class Population{

private:
	double probFickle; 
	double probOne;
	int numAgents;
	int numFickle;
	int numOne;
    Agent** agents;

public:
	//---------------------------------------- Constructors
	Population(int n, double fickle, double one, int s);
    // destructor 
    ~Population() {
    	for (int i = 0; i < numAgents ; i++){
    		delete agents[i];
    	}
        delete[] agents;
    }
    //------------------------------------ Inline functions	
	// return the number of agents
	int size() const 				{ return numAgents; }
	//---------------------------------------- Prototypes
	void sendMessage(int sender, int receiver);
	bool consensusReached();
	int consensusValue();
	ostream& print(ostream& out) const;

};


inline ostream& operator<<( ostream& out, const Population& ppl ) {
    return ppl.print( out );
}

#endif