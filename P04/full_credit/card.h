#ifndef __CARD_H
#define __CARD_H
#include <vector>
#include <string>


class Card{

private:

    std::string _questions;

    std::string _answers;

    

public:

    Card(std::string questions, std::string answers);

    std::string attempt(std::string response);

    friend std::ostream &operator<<(std::ostream &ost,const Card &m);

    

};

#endif
