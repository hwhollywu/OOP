// ----------------------------------------------------------
// Block class for Problem Set 6.					block.hpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "SPtr.hpp"

class Block{

private:
    const SPtr p;
	const int serialNo = Serial::newID(); 
    const int level;
	
public:
	//--------------------------------------- Constructors
    Block(SPtr p);
    ~Block();
    // Delete copy constructor 
    Block(const Block& ) =delete;    
    // Delete copy assignment
    Block& operator=(const Block& ) =delete;    
    // Default move constructor
    Block(Block&& ) =default;
    // Default move assignement
    Block& operator=( Block&& other)=default;
	//------------------------------------ Inline functions	
    // returns the id of the currect block;
    int serialId() const { return serialNo; }
	// returns the level of the current block.
	int blkLevel(){return level; }
};

#endif 