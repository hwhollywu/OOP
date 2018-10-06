// ----------------------------------------------------------
// Think A Dot Model for Problem Set 3.			thinkadot.cpp
// Author: Hao Wu 
// Date: September 30, 2018.
// -----------------------------------------------------------

#include "thinkadot.hpp"

//------------------------------------------------------------
// Print the think-a-dot machine status using text
void ThinkaDot::print(ostream& out) const {
	out << "Current state of the machine:" << endl;
	flops[0].print(out);
	out << " ";
	flops[1].print(out);
	out << " ";
	flops[2].print(out);
	out << endl;
	out << " ";
	flops[3].print(out);
	out << " ";
	flops[4].print(out);
	out << endl;
	flops[5].print(out);
	out << " ";
	flops[6].print(out);
	out << " "; 
	flops[7].print(out);
	out << endl;
}

//------------------------------------------------------------
// Rest all flip-flops to be left or right 
void ThinkaDot::reset(char ch){
	for (unsigned int i = 0 ; i < sizeof(flops); i = i + 1){
		if (ch =='L'){
			flops[i].setStatus('L');
		}else{
			flops[i].setStatus('R');
		}
	}
	// print the state of machine after resetting 
	cout << "Reset the machine to " << ch << "!" <<endl;
}

//------------------------------------------------------------
// Play the think-a-dot game by dropping a from a hole
void ThinkaDot::play(char ch){
	int curr; // represent the current flip-flop index
	char exithole; // represent the exit hole 
	// entering the hole: set flip-flop index
	if (ch == 'A') curr = 1;
	if (ch == 'B') curr = 2;
	if (ch == 'C') curr = 3;
	// keep playing until flip-flop reaches 
	while(curr != 6 && curr != 7 && curr != 8){
		curr = playFlipFlop(curr);
	}
	// finding the exit hole: either 'P' or 'Q'
	if (curr == 6) exithole = 'P';
	if (curr == 8) exithole = 'Q';
	if (curr == 7 && (flops[curr-1].isLeft())) exithole = 'P';
	if (curr == 7 && !(flops[curr-1].isLeft())) exithole = 'Q';
	// flip the bottom layer's flip-flop state before exit
	flops[curr-1].flip();
	// print out exit hole
	cout << "Exit from " << exithole << "!" <<endl;
}

int ThinkaDot::playFlipFlop(int curr){
	FlipFlop f = flops[curr-1]; // get the flip-flop object
	// case 0: if flip-flop 1 and state is left : connect to flipflop 6
	// OR flip-flop 3 and state is right : connect to flipflop 8
	if ((curr == 1 && (f.isLeft())) || (curr == 3 && !(f.isLeft()))) {
		flops[curr-1].flip();
		curr += 5;
	}
	else {
		flops[curr-1].flip();
		// case 1: if flip-flop state is left 
		if (f.isLeft()) curr += 2;
		// case 2: if flip-flop state is right 
		else curr += 3;
	}
	return curr;
}





