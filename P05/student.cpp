#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade): Person(name, email), grade{grade}{}

void Student::add_parent(Parent& parent){
    _parents.push_back(&parent);
}

int Student::parents(){
    return _parents.size();
}

Parent& Student::parent(int index){
    if(index < 0 || index >= _parents.size())
    throw std::out_of_range{"Invalid value"};
       
}

std::string Student::full_info(){
    return std::string(name) + std::string(email) + std::to_string(grade);

}
