#include "parent.h"
#include "student.h"

#include <stdexcept>


Parent::Parent(std::string name, std::string email): Person(name, email){}

void Parent::add_student(Student& student){
    _students.push_back(&student);
}

int Parent::students(){
    return _students.size();
}

Student& Parent::student(int index){
    if(index < 0 || index > _students.size())
    throw std::out_of_range{"Invalid value"};
    
}

std::string Parent::full_info(){
    return name + email;

}
