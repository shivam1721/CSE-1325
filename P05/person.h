#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <string>
 
class Person{
public:
    Person(std::string name, std::string email);
    std::string to_string();
    virtual std::string full_info() = 0;
    friend std::ostream &operator<<(std::ostream &ost,const Person& person);

protected:
    std::string name;
    std::string email;
       
};

#endif

