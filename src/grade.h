/*
 * grade.h
 *
 *  Created on: Nov 5, 2017
 *      Author: ydochung
 */

#ifndef GRADE_H_
#define GRADE_H_

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);



#endif /* GRADE_H_ */
