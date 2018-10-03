// ----------------------------------------------------------
// Main Program for Problem Set 1.					main.cpp
// Author: Hao Wu 
// Date: September 10, 2018.
// -----------------------------------------------------------

#include "tools.hpp"

void run();

// ----------------------------------------------------------
// Main function. Print a header, a user-interactive 
// information function, and termination message. 

int main() {
	banner();
	run();
	bye();
}

// ----------------------------------------------------------
//  This function asks for user's name and year of birth, and 
//  calculates the age of the user by the current time.

void run() {
	string first, last;
	int yob;
	// use yob2 to check if there are non-numbers 
	// after numbers in the input, e.g.'199x'
	char yob2;
	cout << "Please enter your first name: ";
	cin >> first;
	if (!cin.good()) fatal("Error reading first name");

	cout << "Please enter your last name: ";
	cin >> last;
	if (!cin.good()) fatal("Error reading last name");

	cout << "Please enter the year of your birth: ";
	cin >> yob;
	if (!cin.good()) fatal("Error reading year of birth");

	// check if yob input is a valid number
	while (1) {
		if (cin.good()){
			yob2 = getchar();
			if (yob2 == '\n') {
				break;
			}
		}
		cin.clear();
		cin.ignore(256,'\n');
		cout << "The input is not valid! Please try again: ";
		cin >> yob;
	}
	// calculate the age and the current year
	time_t t;
	struct tm *localTime;
	time( &t ); // get current time
	localTime = localtime( &t ); // break into parts yr-mon-day
	int currentyear = localTime->tm_year + 1900; // tm_year counts years from 1900
	int age = currentyear - yob;
	cout << first << " " << last << " becomes ";
	cout << age << " years old in " << currentyear << "." << endl;
}

