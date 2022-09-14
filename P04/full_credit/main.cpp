#include "deck.h"
#include <iostream>

int main() {

std::cout << "Select number of terms for each definitions (-1 to Exit)" << std::endl;

    Deck a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,f1,f2,f3,f4;

    a1.add_card("Reuse and extension of fields and method implementations from another class","Inheritance");

    a2.add_card("Bundling data and code into a restricted container","Encapsulation");

    a3.add_card("A special class member that creates and initializes an object from the class","Constructor");

    a4.add_card("A special class member that cleans up when an object is deleted","Destructor");

    a5.add_card("A method that returns the value of a private variable","Getter");

    a6.add_card("A method that changes the value of a private variable","Setter");

    a7.add_card("A function that manipulates data in a class","Method");

    a8.add_card("A statement that introduces a name with an associated type into a scope","Declaration");

    a9.add_card("A declaration that also fully specifies the entity declared","Definition");

    a10.add_card("A procedure for solving a specific problem, expressed in terms of an ordered set of actionsto execute","Algorithm");

    

    f1.add_false_answers("Composition");

    f2.add_false_answers("Operator");

    f3.add_false_answers("Getters");

    f4.add_false_answers("Setters");

    

    return 0;

     

}
