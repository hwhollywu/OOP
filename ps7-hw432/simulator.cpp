// ----------------------------------------------------------
// Simulator class for Problem Set 7.			simulator.cpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#include "simulator.hpp"

//------------------------------------------------------------
// Constructor
Simulator::
Simulator(Population& p){
	rounds = 0;
	ppl = &p;
};  

// ----------------------------------------------------------
//  This function returns a uniformly-distributed random 
// integer in the range [0, ... n-1].
int uRandom( int n ) {
  long int usefulMax = RAND_MAX - ((RAND_MAX - n) +1)%n;
  long int r;
  do { r = random(); }
  while ( r > usefulMax );
  return r % n;
}

// ----------------------------------------------------------
//  This function runs the simulation for as many rounds as 
//  it takes to reach consensus. Return the consensus value.
void Simulator::
run(){
	// keep taking random communication rounds 
	while(!ppl->consensusReached()){
		// increment number of rounds
		rounds += 1;
		// select a random pair of agents as sender and receiver 
		int n = ppl->size();
		int sender = uRandom(n);
		int receiver = uRandom(n - 1);
		//  keep sender and receiver distinct
		if (receiver >= sender){
			receiver += 1;
		}
		ppl->sendMessage(sender,receiver);
	}
}
