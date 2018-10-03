// ----------------------------------------------------------
// Flip Flop Model for Problem Set 3.			flipflop.hpp
// Author: Hao Wu 
// Date: September 30, 2018.
// -----------------------------------------------------------

#ifndef FLIPFLOP_HPP
#define FLIPFLOP_HPP

#include "tools.hpp"

class FlipFlop {
private:
    enum FlipFlopStatus {LEFT, RIGHT};

    FlipFlopStatus status{LEFT};

public:
	//---------------------------------------- Constructors
    FlipFlop() = default;   
    //---------------------------------------- Prototypes
    void print(ostream& out) const;
    char flip(); 
    void setStatus(char ch);
    //---------------------------------------- Inline functions
    FlipFlopStatus getStatus()			{ return status; }
    bool isLeft()                   	{ return status == LEFT; }
};


#endif 
