// ----------------------------------------------------------
// Block class for Problem Set 6.					block.hpp
// Author: Hao Wu 
// Date: Nov 27, 2018.
// -----------------------------------------------------------

#ifndef BLOCK_HPP
#define BLOCK_HPP


class Block{

private:
	int ch;
	
public:
	//--------------------------------------- Constructors
    Fickle() = default;
    ~Fickle() = default;
    Fickle(int c){ ch = c; }
    // Default copy constructor 
    Fickle( const Fickle& ) 		  		 =default;    
    // Default copy assignment
    Fickle& operator=( const Fickle& ) 	 	 =default;    
    // Default move constructor
    Fickle( Fickle&& )						 =default;
    // move assignement
    Fickle& operator=( Fickle&& other){ 
    	ch = other.ch;
    	return *this;
    }
      
	//------------------------------------ Inline functions	
	// update to the fickle agent by the message m.
	virtual void update(int m)					{ ch = m; }
	// returns the current choice.
	virtual int choice() const 					{ return ch; }
};

#endif 