//============================================================================
// Name        : AcceleratedCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>

using namespace std;


void framing(){
	/*
		 * Please enter your first name: Alex
		 * ****************
		   *              *
		   * Hello, Alex! *
		   *              *
		   ****************
		 * */

		// ask for the person's name
		cout << "Please enter your first name: ";

		// read the name
		string name;
		cin >> name;

		// build the message that we intend to write
		const string greeting = "Hello, " + name + "!";

		// the number of blanks surrounding the greeting
		int vertical_pad = 1;
		int horizontal_pad = 1;

		// Exercises 2-3 ask the user to supply the amount of spacing
		cout << "Enter the amount of vertical spacing: ";
		cin >> vertical_pad;
		cout << "Enter the amount of horizontal spacing: ";
		cin >> horizontal_pad;

		// the number of rows and columns to write
		const int rows = vertical_pad*2 + 3;
		const string::size_type cols = greeting.size() + horizontal_pad*2+2;

		// write a blank line to separate the output from the input
		cout << endl;

		// write |rows| rows of output
		// invariant: we have written r rows so far
		for (int r = 0; r != rows; ++r){
			string::size_type c= 0;

			//invariant: we have written c characters so far in the current row
			while (c != cols){
				// is it time to write the greeting?
				if (r == vertical_pad + 1 && c == horizontal_pad + 1){
					cout << greeting;
					c += greeting.size();
				}
				else{
					// are we on the border?
					if (r == 0 || r == rows -1 || c == 0 || c == cols-1){
						cout << "*";
					}
					else{
						cout << " ";
					}
					++c;
				}
			}
			cout << endl;
		}
}

int main() {
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for and read the homework grades
	cout << "Enter all your homework grades, "
			"followed by end-of-file: ";

	vector<double> homework;
	double x;
	//invariant: homework contains all the homework grades read so far
	while (cin >> x) homework.push_back(x);

	// check that the student entered some homework grades
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0){
		cout << endl << "You must enter your grades. "
						"please try again. " << endl;
		return 1;
	}

	// sort the grades
	sort(homework.begin(), homework.end());

	// compute the median homework grade
	vec_sz mid = size/2;
	double median;
	median = size%2 == 0? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

	// compute and write the final grade
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * median
		 << setprecision(prec) << endl;

	return 0;
}
