// ----------------------------------------------------------
// Inventory class for Problem Set 8.			inventory.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "blockchain.hpp"
#include <map>

class Inventory{

private:
	std::map<Blockchain, int> longest;

public:
	//---------------------------------------- Constructors
    // Constructors
    Inventory() =default;
    // Destructor
    ~Inventory()=default;
    // copy constructor
    Inventory( const Inventory& )=default; 
    // copy assignment   
    Inventory& operator=( const Inventory& )=default;    
    // Default move constructor
    Inventory( Inventory&& )=default;
    // Default move assignement
    Inventory& operator=( Inventory&& other)=default;
    //---------------------------------- Inline functions
	//---------------------------------- Function Prototypes
	void add(Blockchain bc);
	void sub(Blockchain bc);
	ostream& print(ostream& out) const;
};



#endif