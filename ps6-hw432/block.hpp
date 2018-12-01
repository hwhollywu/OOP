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
    // Constructors
    Block() : p(SPtr()), level(0){}
    Block(SPtr sp, int l) : p(sp), level(l){}
    // Default destructors
    ~Block()=default;
    // Delete copy constructor 
    Block(const Block& ) =delete;    
    // Delete copy assignment
    Block& operator=(const Block& ) =delete;    
    // Default move constructor
    Block(Block&& ) =default;
    // Default move assignement
    Block& operator=( Block&& other)=default;
	//------------------------------------ Inline functions	
    // return a regular pointer to the last block
    // Block* last(){return p.get();}
    // returns the id of the currect block;
    int serialId() const { return serialNo; }
	// returns the level of the current block.
	int blkLevel() const { return level; }
    ostream& print(ostream& out) const;
    void printChain() const;
};


inline ostream& operator<<( ostream& out, const Block& b ) {
    return b.print( out );
}

#endif 