#include "semester.h"

Semester::load_semester(std::istream& ist) {
    std::string s;
    std::getline(ist, s);
    _semester = semester_opt_string(s);
}

std::string to_string(Semester semester) {
    if(semester == Semester::FALL) return "fall";
    else if(semester == Semester::SPRING) return "spring";
    else if(semester == Semester::SUMMER) return "summer";
    else throw std::out_of_range("Invalid semester");
}

Semester semester_opt_string(Std::string s) {
    if(s == "fall") return Semester::FALL;
    else if(s == "spring") return Semester::SPRING;
    else if(s == "summer") Semester::SUMMER;
    else throw std::out_of_range("Invalid semester");
}

std::ostream& operator<<(std::ostream& ost, const Semester& semester) {
    ost << to_string(semester);
    return ost;
}


