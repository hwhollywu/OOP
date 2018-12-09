// ----------------------------------------------------------
// Population class for Problem Set 8.			population.cpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
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
Population(int n,double nak, double fic, double extend){
	numAgents = n;
	probFickle = fic;
	probNak = nak;
	probExtend = extend;
	numFickle = 0;
	numNak = 0;
	numOne = 0;
	// use dynamic aggregation
	agents = new Agent*[numAgents]; 
	// create the genesis block
	Block* genesis = new Block();  
	// create blockchain based on the genesis block
	Blockchain bc0(genesis); 

	for (int i = 0; i < numAgents; i++){
		// add bc to the inventory
		inv.add(bc0);
		// choose the agent type 
		// by comparing probFickle and probCrowd with random double r2 and r3
		double r = dRandom();
		if (probNak > r){
			agents[i] = new Nakamoto(bc0);
			numNak += 1;
		}else if (probFickle > r){
			agents[i] = new Fickle(bc0);
			numFickle += 1;
		}else agents[i] = new Crowd(bc0);
	}
};  


//-----------------------------------------------------------------------
// Prints the population statistics
std::ostream& Population::
printStats(ostream& out) const {
	out << "Population statistics:" << endl;
	out << "      numNak:      "<< numNak << endl;
	out << "   numFickle:      "<< numFickle << endl;
	out << "    numCrowd:      "<< (numAgents - numNak - numFickle) << endl;
	out << "     numOnes:      "<< numOne << endl;
	out << "  probExtend:    " << probExtend << endl;
	out << endl;
	// print the starting inventory
	inv.print(cout);
	out << endl;
	return out;
}

//-----------------------------------------------------------------------
// Prints out each agent’s choice of blockchain, one per line
std::ostream& Population::
print(ostream& out) const {
	for (int i = 0; i < numAgents; i++){
		out <<"Agent "<<i<<" choice: ";
		Blockchain bc = agents[i]->choice();
		bc.print(out);
	}
	return out;
}

//-----------------------------------------------------------------------
// Extend a receiver blockchain given the receiver number.
void Population::
extend(int receiver){
	Blockchain bc_old = agents[receiver]->choice();
	Blockchain bc_new = agents[receiver]->extend();
	((AgentBase*) agents[receiver])->ch = bc_new;
	cout << "  extend(" << receiver << ")" <<endl;
	cout << "  New blockchain: " << bc_new;
	inv.sub(bc_old);
	inv.add(bc_new);
	inv.print(cout);
}

//-----------------------------------------------------------------------
// Simulates a single communication step from sender to receiver.
void Population::
sendMessage(int sender, int receiver){
	// the original choice in receiver		 
	Blockchain bc_old = agents[receiver]->choice(); 
	agents[receiver]->update(agents[sender]->choice());
	// the updated choice in receiver
	Blockchain bc_new = agents[receiver]->choice(); 
	// update and print the inventory if the choices are different
	if (!(bc_old == bc_new)){
		inv.sub(bc_old);
		inv.add(bc_new);
		inv.print(cout);
	}
}


