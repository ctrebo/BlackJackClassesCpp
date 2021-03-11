#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <iostream>
#include <array>
#include <ctime>
#include <random>



class Deck
{
public:
  using array_type = std::array<Card, 52>;
  using index_type = array_type::size_type;

private:
  array_type m_deck{};
  index_type m_cardIndex{0};


public:
    Deck();
    void print();
    void shuffle();
    Card& dealCard();
};
#endif