#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"

class Game
{
public:
	Game();

private:
	Player player, dealer;
	Deck deck;

	void initalize();
	void playerTurn();
	void dealerTurn();
	void printWinner();
	bool keepPlaying();

public:
	void play();
};

#endif