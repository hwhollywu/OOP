// ----------------------------------------------------------
// Think A Dot Model for Problem Set 3.			thinkadot.hpp
// Author: Hao Wu 
// Date: September 30, 2018.
// -----------------------------------------------------------

#ifndef THINKADOT_HPP
#define THINKADOT_HPP

#include "flipflop.hpp"

class ThinkaDot {
private:
	FlipFlop* flops = new FlipFlop[8];

public:
	//---------------------------------------- Constructors
	//initialize all the flip-flops to the left position
	ThinkaDot() = default;   

    //---------------------------------------- Prototypes
	void reset(char ch);
	void play(char ch);
	int playFlipFlop(int curr);
	void print(ostream& out) const;
};



#endif 