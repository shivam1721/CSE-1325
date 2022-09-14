#ifndef __PET_H
#define __PET_H
#include <iostream>
#include <vector>
#include <map>
 
enum Type {INSECT, REPTILE, AMPHIBIAN, DINOSAUR};
std::string to_string(Type type);
 
 
class Pet {
    std::string Name;
    Type type;
    double age;
    double human_yr;
  public:
    Pet(std::string name, Type t, double d);
    double human_years(double ag); // 1
    std::string to_string();
};
 

#endif
