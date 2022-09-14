#include "person.h"

Person::Person(std::string name, std::string email): name{name}, email{email}{}

std::string Person::to_string() {
    return std::string(name);
}

std::string Person::full_info(){
    return name + "(" + email + ")";
}

std::ostream &operator<<(std::ostream &ost,const Person& person)
 {
     return ost << person.name;
 }
 
