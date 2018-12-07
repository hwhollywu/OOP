// ----------------------------------------------------------
// Population class for Problem Set 7.			population.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

// manage populations with two kinds of agents 
// as well as two possible initial values.

#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "fickle.hpp"
#include "crowd.hpp"
#include "nakamoto.hpp"


class Population{

private:
	int numAgents;
	double probFickle; 
	double probNak; 
	double probExtend;
	int numFickle;
	int numNak;
	int numOne;
    Agent** agents;

public:
	//---------------------------------------- Constructors
	Population(int n,double nak, double fic, double extend);
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
	void extend(int receiver);
	void sendMessage(int sender, int receiver);
	ostream& printStats(ostream& out) const;
	ostream& print(ostream& out) const;
};


inline ostream& operator<<( ostream& out, const Population& ppl ) {
    return ppl.printStats( out );
}

#endif