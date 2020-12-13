#include "Deck.h"

#include <iostream>
#include <array>
#include <ctime>
#include <random>


void Deck::print() {
    for (Card& card : m_deck)
    {
        card.printCard();
        std::cout << ' ';
    }

    std::cout << '\n';
}

void Deck::shuffle() {
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(m_deck.begin(), m_deck.end(), mt);
}

Deck::Deck() {
    index_type card{ 0 };

    auto suits{ static_cast<index_type>(Card::CardSuit::MAX_SUITS) };
    auto ranks{ static_cast<index_type>(Card::CardRank::MAX_RANKS) };

    for (index_type suit{ 0 }; suit < suits; ++suit)
    {
        for (index_type rank{ 0 }; rank < ranks; ++rank)
        {
            m_deck[card] = { static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit) };
            ++card;
        }
    }
}