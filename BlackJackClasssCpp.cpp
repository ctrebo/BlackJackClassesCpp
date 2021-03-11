// BlackJackClasssCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Card.h" 
#include "Deck.h"
#include "Player.h"

#include <iostream>

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}



bool playerTurn(Deck &deck, Player &player) {
	while (true) {
		std::cout << "You have: " << player.getScore();

        if (player.isBust()) {
            return true;
        }
        else {
            if (playerWantsHit()) {
                player.drawCard(deck);
            }
            else {
                return false;
            }
        }
	}
}

bool dealerTurn(Deck& deck, Player& dealer) {
    while (dealer.getScore() < 17) {
        dealer.drawCard(deck);
    }

    return dealer.isBust();

}

bool playBlackjack(Deck& deck)
{
    Player dealer{};
    dealer.drawCard(deck);

    std::cout << "The dealer is showing: " << dealer.getScore() << '\n';

    Player player{};
    player.drawCard(deck);
    player.drawCard(deck);

    if (playerTurn(deck, player))
    {
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        return true;
    }

    return (player.getScore() > dealer.getScore());
}


int main()
{
	Deck deck{};
	deck.print();
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
