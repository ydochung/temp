//============================================================================
// Name        : AcceleratedCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	/*
	 * Please enter your first name: Alex
	 * ****************
	   *              *
	   * Hello, Alex! *
	   *              *
	   ****************
	 * */
	cout << "Please enter your first name: ";
	string name;
	cin >> name;

	// build the message that we intend to write
	const string greeting = "Hello, " + name + "!";

	// build the second and forth lines of the output
	const string spaces(greeting.size(), ' ');
	const string second = "* " + spaces + " *";

	// build the first and fifth lines of the output
	const string first(second.size(), '*');

	// write it all
	cout << endl;
	cout << first << endl;
	cout << second << endl;
	cout << "* " << greeting << " *" << endl;
	cout << second << endl;
	cout << first << endl;

	const string hello = "hello";
	const string message = hello + ", world" + "!";

	return 0;
}
