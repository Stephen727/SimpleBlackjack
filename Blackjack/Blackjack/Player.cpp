#include "Player.h"

#include <iostream>


Player::Player()
{
}


void Player::addCard(Card card)
{
	hand.push_back(card);
}

void Player::clearHand()
{
	if (!hand.empty())
		hand.erase(hand.begin(), hand.end());
}

void Player::printHand() 
{
	for (int i = 0; i < hand.size(); i++)
	{
		std::cout << hand[i].toString() << std::endl;
	}
}

void Player::printLastCard()
{
	std::cout << hand.back().toString() << std::endl;
}

int Player::getValue()
{
	int value = 0,
		aces = 0;

	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i].getValue() == 1)
			aces++;
		else
			value += hand[i].getValue();
	}

	while (aces)
	{
		aces--;

		if (value + 11 + aces < 22)
			value += 11;
		else
			value++;
	}

	return value;
}