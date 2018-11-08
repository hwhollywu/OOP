// ----------------------------------------------------------
// Population class for Problem Set 5.			population.cpp
// Author: Hao Wu 
// Date: Nov 3, 2018.
// -----------------------------------------------------------

#include "population.hpp"

// ----------------------------------------------------------
//  This function returns a random double in range [0,1)
double dRandom() {
   return random()/(RAND_MAX+1.0); 
 }


//------------------------------------------------------------
// Constructor
Population::
Population(int n, double fickle, double one){
	numAgents = n;
	probFickle = fickle;
	probOne = one;
	numFickle = 0;
	numOne = 0;
	// use dynamic aggregation
	agents = new Agent*[numAgents]; 

	for (int i = 0; i < n; i++){
		// choose the initial choice value 
		// by comparing probOne with random double r1
		double r1 = dRandom();
		// choose the agent type 
		// by comparing probFickle with random double r2
		double r2 = dRandom();
		if (probOne > r1 && probFickle > r2){
			agents[i] = new Fickle(1);
			numFickle += 1;
			numOne += 1;
		}else if (probOne > r1 && probFickle <= r2){
			agents[i] = new Crowd(1);
			numOne += 1;
		}else if (probOne <= r1 && probFickle > r2){
			agents[i] = new Fickle(0);
			numFickle += 1;
		}else agents[i] = new Crowd(0);
	}

};  


//-----------------------------------------------------------------------
// Prints the population statistics
std::ostream& Population::
print(ostream& out) const {
	out << "Population statistics:" << endl;
	out << "   numFickle:    "<< numFickle << endl;
	out << "    numCrowd:    "<< (numAgents - numFickle) << endl;
	out << "     numOnes:    "<< numOne << endl;
	return out;
}

//-----------------------------------------------------------------------
// Simulates a single communication step from sender to receiver.
void Population::
sendMessage(int sender, int receiver){
	// the original choice in receiver		 
	int orig = agents[receiver]->choice(); 
	agents[receiver]->update(agents[sender]->choice());
	// the updated choice in receiver
	int updated = agents[receiver]->choice(); 
	// update numOne
	if(updated != orig){
		if (orig == 0) numOne++;
		else numOne--;
	}
}

//-----------------------------------------------------------------------
// Returns true iff consensus has been reached.
bool Population::
consensusReached(){
	return (numOne == 0 || numOne == numAgents);
}

//-----------------------------------------------------------------------
// Returns the consensus value if consensus has been reached; 
// otherwise it returns -1.
int Population::
consensusValue(){
	if (numOne == 0) return 0;
	else if (numOne == numAgents) return 1;
	else return -1;
}
