#ifndef __DECK_H
#define __DECK_H
#include <vector>
#include <string>
#include "card.h"

class Deck{

private:

    std::vector<Card> _cards;

    std::vector<std::string> _options;

    int _next_card;

    

public:

    void add_card(std::string questions, std::string answers);

    void add_false_answers(std::string false_answers);

    std::vector<std::string> options();

    Card deal();

    

};

#endif


