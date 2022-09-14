#include "pet.h"
   
int main() {
    Pet horse{"Bee", INSECT, 2};
    Pet space{"Turtle", REPTILE, 90};
    Pet star{"Frog", AMPHIBIAN, 10};
    Pet galaxy{"Spinosaurus", DINOSAUR, 117};
    std::cout << horse.to_string() << std::endl;
    std::cout << space.to_string() << std::endl;
    std::cout << star.to_string() << std::endl;
    std::cout << galaxy.to_string() << std::endl;
}
