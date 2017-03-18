#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
public:
	Card(std::string _rank, std::string _suit, int _value)
	{
		rank = _rank;
		suit = _suit;
		value = _value;
	}

private:
	std::string rank;
	std::string suit;
	int value;

public:
	std::string getRank() { return rank; }
	std::string getSuit() { return suit; }
	std::string toString() { return rank + " of " + suit; }
	int getValue() { return value; }
};

#endif