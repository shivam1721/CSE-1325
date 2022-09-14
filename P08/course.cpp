#include "course.h"

Course::Course(Subject subject, int grade); : _subject{subject}, _grade{grade} { }
    
Course::Course(std::istream& ist) : {
    ist >> _grade; 
}

void Course::save(std::ostream& ost) {
    ost << "course\n";
    ost << _grade << '\n'
        << ::to_string(_subject) << '\n';
}

std::string Course::to_string() const {
    return std::to_string(_subject) + "(grade " + std::to_string(_grade) + ")" ;
}

std::ostream& operator<<(std::ostream& ost, const Course& course) {
    ost << to_string();
    return ost;



