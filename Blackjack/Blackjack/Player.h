#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Card.h"

class Player
{
public:
	Player();
	
private:
	std::vector<Card> hand;

public:
	void addCard(Card);
	void clearHand();

	void printHand();
	void printLastCard();
	
	int getValue();
};

#endif