#include "Deck.h"

#include <algorithm>
#include <random>

Deck::Deck()
{
	initialize();
}


void Deck::initialize()
{
	std::string ranks[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	std::string suits[4] = {  "Clubs", "Diamonds", "Hearts", "Spades" };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck.push_back(Card(ranks[j], suits[i], (j + 1) < 10 ? (j + 1) : 10));
		}
	}
}

void Deck::shuffle()
{
	std::default_random_engine engine(std::random_device{}());
	std::shuffle(std::begin(deck), std::end(deck), engine);
}
Card Deck::dealCard()
{
	if (deck.empty())
	{
		initialize();
		shuffle();
	}

	Card card = deck.front();
	deck.erase(deck.begin());
	
	return card;
}