#include "Player.h"
#include "Card.h"
#include "Deck.h"

void Player::drawCard(Deck& deck) {
	m_score += deck.dealCard().getCardValue();
}

int Player::getScore() const {
	return m_score;
}

bool Player::isBust() const {
	return (m_score > maximum_score);
}