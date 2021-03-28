#include<iostream>
#include"playBlackJack.h"
#include"getPlayerChoice.h"
#include"sum.h"
bool playBlackJack(Deck& deck)
{
	int playerTotal = 0;
	int dealerTotal = 0;

	// Дилер получает одну карту
	dealerTotal = sum(dealerTotal,deck.dealCard().getCardValue());
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Игрок получает две карты
	playerTotal = sum(playerTotal, deck.dealCard().getCardValue());
	playerTotal = sum(playerTotal, deck.dealCard().getCardValue());
	if (playerTotal == 21) return true;
	// Игрок начинает
	while (true)
	{
		std::cout << "You have: " << playerTotal << '\n';
		if (playerTotal == 21) return true;
		char choice = getPlayerChoice();
		if (choice == 'N' || choice == 'n')
			break;

		playerTotal = sum(playerTotal, deck.dealCard().getCardValue());
		// Смотрим, не проиграл ли игрок
		if (playerTotal > 21)
			return false;
	}

	// Если игрок не проиграл (у него не больше 21 очка), тогда дилер получает карты до тех пор, пока у него в сумме будет не меньше 17 очков
	while (dealerTotal < 17)
	{
		dealerTotal = sum(dealerTotal, deck.dealCard().getCardValue());
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// Если у дилера больше 21, то он проиграл, а игрок выиграл
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}
