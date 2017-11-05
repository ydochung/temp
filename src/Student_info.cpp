/*
 * Student_info.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: ydochung
 */

#include "Student_info.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y){
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s){
	// read and store the student's name and midterm and final exam grades
	std::cout << "Enter name, midterm and final" << std::endl;
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

istream& read_hw(istream& in, vector<double>& hw){
	if (in){
		// get rid of previous contents
		hw.clear();

		// read homework grades
		std::cout << "Enter homework grades" << std::endl;
		double x;
		while (in >> x){
			hw.push_back(x);
		}

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}



