#include "parent.h"
#include "student.h"


Parent::Parent(std::istream& ist) {
    int s_size;
    ist >> s_size;
    while(s_size--)
    {
       _students.push_back(Student{ist});
    }
}

void Student::save(std::ostream& ost) {
    for(Student* s : _students) s->save(ost);
}



void Parent::add_student(Student& student) {
    _students.push_back(&student);
}

int Parent::students() {return _students.size();}
Student& Parent::student(int index) {
    return *(_students.at(index));
}
std::string Parent::full_info() const {
    std::string info = Person::full_info() + " - Students: ";
    std::string separator;
    for(auto s : _students) {
        info += separator + s->to_string();
        separator = ", ";
    }
    return info;
}
