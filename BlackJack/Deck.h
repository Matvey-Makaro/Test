#pragma once
#include<array>
#include"Card.h"
namespace Const
{
	const int DeckSize = 52;
}
class Deck
{
public:
	Deck();
	void printDeck() const;
	void shuffleDeck();
	const Card& dealCard();


private:
	std::array<Card, Const::DeckSize> m_deck;
	int m_cardIndex = 0;
	static void swapCard(Card& a, Card& b);
	static int getRandomNumber(int min, int max);
};