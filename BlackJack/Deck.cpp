#include<iostream>
#include<cassert>
#include"Deck.h"
Deck::Deck()
{
	int card = 0;
	for (int suit = 0; suit < Card::CardSuit::MAX_SUITS; ++suit)
		for (int rank = 0; rank < Card::CardRank::MAX_RANKS; ++rank)
		{
			m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
			++card;
		}
}
void Deck::printDeck() const
{
	for (auto& card : m_deck)
	{
		card.printCard();
		std::cout << " ";
	}
	std::cout << std::endl;
}

void Deck::swapCard(Card& a, Card& b) 
{
	Card temp = a;
	a = b;
	b = temp;
}

// Генерируем случайное число между min и max (включительно).
// Предполагается, что srand() уже был вызван
int Deck::getRandomNumber(int min, int max) 
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
	// Равномерно распределяем вычисление значения из нашего диапазона
	return static_cast<int>(rand() * fraction * (static_cast<double>(max) - min + 1) + min);
}

void Deck::shuffleDeck()
{
	// Перебираем каждую карту в колоде
	for (int index = 0; index < Const::DeckSize; ++index)
	{
		// Выбираем любую случайную карту
		int swapIndex = getRandomNumber(0, Const::DeckSize - 1);
		// Меняем местами с нашей текущей картой
		swapCard(m_deck[index], m_deck[swapIndex]);
	}
	m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
	assert(m_cardIndex < Const::DeckSize && "m_cardIndex out of range");
	return m_deck[m_cardIndex++];
}
