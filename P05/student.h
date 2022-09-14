#ifndef __STUDENT_H
#define __STUDENT_H

#include <vector>
#include "person.h"

class Parent;

class Student : public Person{
protected:
    int grade;
    std::vector<Parent*> _parents;

public:
    Student(std::string name, std::string email, int grade);
    void add_parent(Parent& parent);
    int parents();
    Parent& parent(int index);
    std::string full_info() override;
 
};

#endif

