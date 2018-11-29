// ----------------------------------------------------------
// Driver class for Problem Set 6.					driver.hpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "blockchain.hpp"


class Driver{

private:
	int size = 10;
	Blockchain bc [size];

public:
	//---------------------------------------- Constructor
    Driver();   
	//---------------------------------------- Prototype
	void start();	
};

#endif 