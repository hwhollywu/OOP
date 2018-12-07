// ----------------------------------------------------------
// Simulator class for Problem Set 7.			simulator.cpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#include "simulator.hpp"

//------------------------------------------------------------
// Constructor
Simulator::
Simulator(Population& p, int r, double extend){
	ppl = &p;
	maxRounds = r;
	probExtend = extend;
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
//  This function returns a random double in range [0,1)
double d2Random() {
   return random()/(RAND_MAX+1.0); 
 }


// ----------------------------------------------------------
//  This function runs the simulation for the max rounds given.
void Simulator::
run(){
	for (int rod = 0; rod < maxRounds; rod++){
		// use r to randomly decide to extend or update 
		double r = d2Random();
		int n = ppl->size();

		if (probExtend > r){
			// to extend: choose an agent at random
			int receiver = uRandom(n);
			ppl->extend(receiver);
		}else{
			// to update: choose a sender and a receiver at random
			int sender = uRandom(n);
			int receiver = uRandom(n - 1);
			//  keep sender and receiver distinct
			if (receiver >= sender){
				receiver += 1;
			ppl->sendMessage(sender,receiver);
			cout << "sendMessage(" << sender << ", " << receiver << ")" << endl;
			}
		}
	}
	// print out a list of agents with their current choices
	ppl->printStats(cout);
}
