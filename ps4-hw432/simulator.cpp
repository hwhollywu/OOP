// ----------------------------------------------------------
// Simulator class for Problem Set 4.			simulator.cpp
// Author: Hao Wu 
// Date: October 26, 2018.
// -----------------------------------------------------------

#include "simulator.hpp"

// ----------------------------------------------------------
//  This function runs the simulation for as many rounds as 
//  it takes to reach consensus. Return the consensus value.
int Simulator::
run(int& rounds){
	// keep taking random communication rounds 
	while((numOne != numAgents) && (numOne != 0)){
		// select a random pair of agents as sender and receiver 
		// j = sender, k = receiver
		int j = uRandom(numAgents);
		int k = uRandom(numAgents - 1);
		//  keep sender and receiver distinct
		if (k == j){
			k += 1;
		}
		int m = agents[j].choice();
		agents[k].update(m);
		// keep track of the number of value ones in agents 
		if (m == 1){
			numOne += 1;
		}else numOne -= 1;
		// increment number of rounds
		rounds += 1;
	}
	// return the consensus value
	if (numOne == numAgents) return 1;
	else return 0;
}

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