// ----------------------------------------------------------
// Main Program for Problem Set 1.					main.cpp
// Author: Hao Wu 
// Date: September 7, 2018.
// Acknowledgement: cplusplus.com 
// http://www.cplusplus.com/reference/ctime/localtime/
// -----------------------------------------------------------

#include "tools.hpp"

void run();

// -----------------------------------------------------------
// Main function. Print a header, a user-interactive information 
// function, and termination message. 

int main() {
	banner();
	run();
	bye();
}

// -----------------------------------------------------------
//  This function asks for user's name and year of birth, and 
//  calculates the age of the user by the current time.

void run() {
	string first, last;
	int yob;
	cout << "Please enter your first name: ";
	cin >> first;
	if (!cin.good())
		fatal("An invalid input was entered!");
	cout << "Please enter your last name: ";
	cin >> last;
	if (!cin.good())
		fatal("An invalid input was entered!");
	cout << "Please enter the year of your birth: ";
	cin >> yob;
	// check if yob input is a valid number
	if (!cin.good())
		fatal("An invalid year was entered!");
	// calculate the age and the current year
	time_t t;
	struct tm *localTime;
	time( &t );
	localTime = localtime( &t );
	int currentyear = localTime->tm_year + 1900;
	int age = currentyear - yob;
	cout << first << " " << last << " becomes ";
	cout << age << " years old in " << currentyear << ".";
}


