#include "teacher.h"

void Teacher::save(std::ostream& ost) {
    Person::save(ost);
}

Teacher::Teacher(std::istream& ist) {
    std::getline(ist, _name);
    std::getline(ist, _email);
}
void Teacher::save(std::ostream& ost) {
    ost << _name << '\n' << _email << '\n';
}

std::string Teacher::full_info() const {return _name + " (" + _email + ")";}

}

