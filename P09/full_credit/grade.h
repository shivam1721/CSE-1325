#ifndef __GRADE_
#define __GRADE_

#include <iostream>

enum class Grade {A, B, C, D, F, I, X};

std::ostream& operator<<(std::ostream& ost, const Grade& grade);
Grade load_grade(std::istream& ist);

#endif
