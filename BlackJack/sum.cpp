#include"Card.h"
int sum(int totalValue, int cardValue)
{
	if (cardValue == Card(Card::CardRank::RANK_ACE).getCardValue() && (totalValue + cardValue) > 21)
		return ++totalValue;
	else
		return totalValue + cardValue;
}