#include "grade.h"

std::ostream& operator<<(std::ostream& ost, const Grade& grade) {
    ost << ((grade == Grade::A) ? "A" :
           ((grade == Grade::B) ? "B" :
           ((grade == Grade::C) ? "C" :
           ((grade == Grade::D) ? "D" :
           ((grade == Grade::F) ? "F" :
           ((grade == Grade::I) ? "Incomplete" : "In Porgress"));
    return ost;
}

Grade load_grade(std::istream& ist) {
    std::string s;
    std::getline(ist, s);
    if(s == "a") return Grade::A;
    if(s == "b") return Grade::B;
    if(s == "c") return Grade::C;
    if(s == "d") return Grade::D;
    if(s == "f") return Grade::F;
    if(s == "i") return Grade::I;
    if(s == "x") return Grade::X;
    throw std::runtime_error{std::string{"Invalid grade: " + s}};
}
