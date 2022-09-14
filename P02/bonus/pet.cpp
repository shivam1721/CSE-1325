#include "pet.h"

Pet::Pet(std::string name, Type t, double d) : Name{name}, type{t}, age{d}{
    if (d < 0) {
        std::cerr << "Age is Invalid: " << std::to_string(d) << std::endl;
        exit(1);
    }
}
 
double Pet::human_years(double ag){
    human_yr = age;
    if(age == 2)
    {
        human_yr = human_yr * 80/1;
    }
    else if(age == 90)
    {
        human_yr = human_yr * 80/150;
    }
    else if(age == 10)
    {
        human_yr = human_yr * 80/12;
    }
    else if(age == 117)
    {
        human_yr = human_yr * 80/300;
    }
    return human_yr;
    
}
 
 
std::string Pet::to_string() {
    return std::string(Name) + " is a " +  ::to_string(type) + " age " + std::to_string(age) + " or " + std::to_string(human_yr) + " in human-equivalent years " ;
}
 
std::string to_string(Type type) {
    std::vector<std::string> v = {"Insect", "Reptile", "Amphibian", "Dinosaur"};
    return v[type];
}

