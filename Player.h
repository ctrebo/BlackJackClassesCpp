#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Card.h"

int constexpr maximum_score{ 21 };

class Player {
private:
	int m_score{ 0 };

public:
	void drawCard(Deck& deck);
	int getScore() const;
	bool isBust() const;
};

#endif // !1
