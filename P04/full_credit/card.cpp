#include "card.h"
#include <iostream>

Card::Card(std::string questions, std::string answers): _questions{questions}, _answers{answers}{}

std::string Card::attempt(std::string response){

    for(char & c: response) c = toupper(c);
    if(response == _answers)

        return "Correct";

    else

        return " X - Correct answer was " + _answers;

}


std::ostream &operator<<(std::ostream &ost,const Card &m){
   return ost << m._questions;
}

