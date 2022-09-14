#include "pet.h"
   
int main() {
    Pet bee{"Bee", INSECT, 2};
    bee.human_years(2);
    Pet turt{"Turtle", REPTILE, 90};
    turt.human_years(90);
    Pet fro{"Frog", AMPHIBIAN, 10};
    fro.human_years(10);
    Pet spin{"Spinosaurus", DINOSAUR, 117};
    spin.human_years(117);
    std::cout << bee.to_string() << std::endl;
    std::cout << turt.to_string() << std::endl;
    std::cout << fro.to_string() << std::endl;
    std::cout << spin.to_string() << std::endl;
}
 
