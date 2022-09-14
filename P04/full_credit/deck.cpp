#include "deck.h"
#include <algorithm>

void Deck::add_card(std::string questions, std::string answers) {

    _cards.push_back(Card{questions,answers});

    _options.push_back(answers);

};

void Deck::add_false_answers(std::string false_answers){

    _options.push_back(false_answers);

};

std::vector<std::string> Deck::options(){

    std::sort(_options.begin(), _options.end());
    return _options;

};





 
