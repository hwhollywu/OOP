// ----------------------------------------------------------
// Block class for Problem Set 7.					block.hpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "SPtr.hpp"

class Block{

private:
    SPtr sp;
	const int serialNo = sp.id(); 
    const int level;
	
public:
	//--------------------------------------- Constructors
    // Constructors
    Block() : sp(SPtr()), level(0){}
    Block(SPtr p) : sp( p ), level( (p.getTarget())->blkLevel()+1 ){}
    // Destructor
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
    Block* last(){return sp.getTarget();}
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