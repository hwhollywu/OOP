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
//  This function runs the simulation for the max rounds given.
void Simulator::
run(){
	cout << "Starting simulation with probExtend = "<<probExtend<<endl;
	for (int rod = 0; rod < maxRounds; rod++){
		// use r to randomly decide to extend or update 
		double r = random()/(RAND_MAX+1.0); 
		int n = ppl->size();
		// use u1 as a random receiver/sender number
		int u1 = uRandom(n);

		if (probExtend > r){
			// to extend: choose an agent at random
			ppl->extend(u1);
		}else{
			// to update: choose another receiver at random
			int u2 = uRandom(n - 1);
			//  keep sender and receiver distinct
			if (u2 >= u1){
				u2 += 1;
			}			
			cout << "  sendMessage(" << u1 << ", " << u2 << ")" << endl;
			ppl->sendMessage(u1,u2);
		}
	}
	// print out a list of agents with their current choices
	cout << "Current blockchain choices after "<<maxRounds<<" rounds:"<<endl;
	ppl->print(cout);
}
