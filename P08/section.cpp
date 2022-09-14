#include "section.h"

Section::Section(Course course, Semester semester, int year); : Course{course}, _semester{semester} , _year{year} { }
    
Section::Section(std::istream& ist) : Course{ist} {
    ist >> _year; 
}

void Section::save(std::ostream& ost) {
    ost << "Section\n";
    Course::save(ost);
    ost << _year << '\n'
        << ::to_string(_course) << '\n' << ::to_string(_semester) << '\n';
}

std::string Section::to_string() const {
    return std::to_string(_subject) + "(grade " + std::to_string(_grade) + ")" + " for " +    std::to_string(_semester) +  std::to_string(_year) ;
}

std::ostream& operator<<(std::ostream& ost, const Section& section) {
    ost << to_string();
    return ost;
}




