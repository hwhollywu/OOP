// ----------------------------------------------------------
// Block class for Problem Set 6.					block.cpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#include "Block.hpp"

//------------------------------------------------------------------------------
//  constructor
Block::Block(SPtr sp) : p(sp) {
    cout << "  Default constructor called for Block " << serialId() << endl;
    if (sp.get() == nullptr){
    	level = 0;
    }else{
    	level = sp.get().blkLevel() + 1;
    }
}


//------------------------------------------------------------------------------
// Destructor
Block::~Block() {
    cout << "  Destructor called for Block " << serialId() << endl;
    p.reset();
}