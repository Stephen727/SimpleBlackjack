#include "Game.h"

#include <iostream>


Game::Game()
{
	deck.shuffle();
}


void Game::initalize()
{
	player.clearHand();
	dealer.clearHand();

	player.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());
	player.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());

	system("CLS");
	std::cout << "Dealer:" << std::endl;
	dealer.printLastCard();
	std::cout << std::endl;

	std::cout << "Player:" << std::endl;
	player.printHand();
	std::cout << "Current Value = " << player.getValue() << std::endl << std::endl;
}

void Game::playerTurn()
{
	while (player.getValue() < 21)
	{
		char input;

		std::cout << "Type [h] to hit or [s] to stand: ";

		std::cin >> input;
		input = toupper(input);

		if (input == 'H')
			player.addCard(deck.dealCard());
		else if (input == 'S')
			return;

		system("CLS");
		std::cout << "Dealer:" << std::endl;
		dealer.printLastCard();
		std::cout << std::endl;

		std::cout << "Player:" << std::endl;
		player.printHand();
		std::cout << "Current Value = " << player.getValue() << std::endl << std::endl;
	}
}

void Game::dealerTurn()
{
	while (dealer.getValue() < 17 && player.getValue() < 22)
		dealer.addCard(deck.dealCard());
}

void Game::printWinner()
{
	system("CLS");
	std::cout << "Dealer:" << std::endl;
	dealer.printHand();
	std::cout << "Current Value = " << dealer.getValue() << std::endl << std::endl;

	std::cout << "Player:" << std::endl;
	player.printHand();
	std::cout << "Current Value = " << player.getValue() << std::endl << std::endl;

	if (player.getValue() > 21)
		std::cout << "You lose." << std::endl;
	else if (dealer.getValue() > 21)
		std::cout << "You win!" << std::endl;
	else if (dealer.getValue() > player.getValue())
		std::cout << "You lose." << std::endl;
	else if (player.getValue() > dealer.getValue())
		std::cout << "You win!" << std::endl;
	else
		std::cout << "Draw." << std::endl;
}

bool Game::keepPlaying()
{
	std::cout << "Play again? [Y]es or [N]o: ";

	char input;
	std::cin >> input;
	input = toupper(input);

	if (input == 'Y')
		return true;
	else if (input == 'N')
		return false;
	else
		keepPlaying();
}


void Game::play()
{
	do
	{
		initalize();
		playerTurn();
		dealerTurn();
		printWinner();
	} while (keepPlaying());
}
