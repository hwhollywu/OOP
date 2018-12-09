// ----------------------------------------------------------
// Inventory class for Problem Set 8.			inventory.cpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#include "inventory.hpp"
#include "tools.hpp"

//-----------------------------------------------------------------------
// Add a new blockchain to the inventory
void Inventory::
add(Blockchain bc){
	std::map<Blockchain, int>::iterator pos;
	pos = longest.find(bc);
	// if key already exist, add value of the given blockchain
	if (pos!=longest.end()) {
		longest[bc] += 1; 
	} else {
		// adds new pair <bc,1> to the map
		longest.insert (std::pair<Blockchain, int>(bc,1)); 
	}
};

//-----------------------------------------------------------------------
// Subtract an old blockchain from the inventory
void Inventory::
sub(Blockchain bc){
	std::map<Blockchain, int>::iterator pos;
	pos = longest.find(bc);
	// if key does not exists, catch exception
	if (pos==longest.end()){
		fatal("Substracting a blockchain that does not exist!");
	}
	// if there are more than one instances of the given bc
	else if (pos->second > 1){
		longest[bc] -= 1;
	}else{
		longest.erase(bc);
	}
};

//-----------------------------------------------------------------------
// Prints the inventory 
ostream& Inventory::
print(ostream& out) const {
	out << "Inventory: "<<longest.size()<<" active blockchain(s):" << endl;
	// print map by blockchain length
	std::map<Blockchain, int>::const_iterator pos;
	for (pos=longest.begin(); pos!=longest.end(); ++pos){
		cout<<"  "<<pos->second<< " copies of 	"<<pos->first;
	}
	return out;
}
