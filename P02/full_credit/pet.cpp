#include "pet.h"

Pet::Pet(std::string name, Type t, double d) : Name{name}, type{t}, age{d} {
    if (d < 0) {
        std::cerr << "Age is Invalid: " << std::to_string(d) << std::endl;
        exit(1);
    }
}
std::string Pet::to_string() {
    return std::string(Name) + " is a " +  ::to_string(type) + " age " + std::to_string(age);
}
 
std::string to_string(Type type) {
    std::vector<std::string> v = {"Insect", "Reptile", "Amphibian", "Dinosaur"};
    return v[type];
}
