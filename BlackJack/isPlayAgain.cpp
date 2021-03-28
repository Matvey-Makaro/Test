#include<iostream>
bool isPlayAgain()
{
	std::cout << "Do you want to play again?(Y/N): ";
	char choice;
	std::cin >> choice;
	while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
	{
		std::cout << "Incorrect input! Try again: ";
		std::cin >> choice;
	}
	system("CLS");
	if (choice == 'Y' || choice == 'y')
		return true;
	else
		return false;
}