#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade)
  :  Person(name, email), _grade{grade} { }


Student::Student(std::istream& ist) {
    int p_size;
    std::getline(ist, _grade);
    ist >> p_size;
    while(p_size--)
    {
       _parents.push_back(Parent{ist});
    }
}


void Student::save(std::ostream& ost) {
    ost << _grade << std::endl;
    for(Parent* p : _parents) p->save(ost);
}



void Student::add_parent(Parent& parent) {
    _parents.push_back(&parent);
}

int Student::parents() {return _parents.size();}
Parent& Student::parent(int index) {
    return *(_parents.at(index));
}

std::string Student::full_info() const {
    std::string info = Person::full_info() + " in grade " + std::to_string(_grade) + " - Parents: ";
    std::string separator;
    for(Parent* p : _parents) {
        info += separator + p->to_string();
        separator = ", ";
    }
    return info;
}
