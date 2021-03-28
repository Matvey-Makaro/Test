#include<iostream>              // добавить просьбу ввес
char getPlayerChoice()
{
	std::cout << "Do you want to take card?(Y/N): ";
	char choice;
	std::cin >> choice;
	while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
	{
		std::cout << "Incorrect input! Try again: ";
		std::cin >> choice;
	}

	return choice;
}

