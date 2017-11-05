/*
 * grade.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: ydochung
 */


#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;

double grade(double midterm, double final, double homework){
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw){
	if (hw.size() == 0) throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s){
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s){
	return grade(s) < 60;
}

bool did_all_hw(const Student_info& s){
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double grade_aux(const Student_info& s){
	try{
		return grade(s);
	}
	catch (domain_error){
		return grade(s.midterm, s.final, 0);
	}
}

double median_analysis(const vector<Student_info>& students){
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

void write_analysis(std::ostream& out, const std::string& name, double analysis(const vector<Student_info>&),
				    const vector<Student_info>& did, const vector<Student_info>& didnt){
	out << name << ": median(did) = " << analysis(did) << ", median(didn't) = " << analysis(didnt) << std::endl;
}
