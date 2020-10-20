#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int Success_Message(int ranNum);
int Menu();
int New_Game();

int main()
{
	if (New_Game() == 1)
	{
		return 1; // terminates program
	}
	else
		New_Game();


	return 0;
}

int New_Game()
{
	int ranNum;
	int numOfGuesses{}; //initialized to zero.
	int guess{}; //initialized to zero before user input.

	srand(unsigned int(time(NULL))); //Seeds random number generator
	ranNum = rand() % 10 + 1; //Generates random numbers between 0 and 100

	cout << "\n\n\nThe computer has generated a random number between 0 and 100\n";
	cout << "You have 20 guesses to correctly guess what the random number is\n\n";

	cout << "Enter your first guess: ";
	cin >> guess;

	while (numOfGuesses < 20)
	{
		if (guess == ranNum)
		{
			if (Success_Message(ranNum) == 0)
			{
				New_Game();
			}
			else if (Success_Message(ranNum) == 1)
			{
				return 1;
			}
		}

		cout << "Nope - that's not the random number.\n";

		cout << "Try again: ";
		cin >> guess;
		++numOfGuesses;
	}

	cout << "\n\nYou lose!";
}

int Success_Message(int ranNum)
{
	cout << "You win!\n The secret number was " << ranNum << endl;

	if (Menu() == 0)
	{
		return 0;
	}
	else if (Menu() == 1)
	{
		return 1;
	}
}

int Menu()
{
	char selection;

	cout << "\n\n\nSelect one of the following: \n";

	do
	{
		cout << "New Game - 1\n";
		cout << "Quit - 2\n";
		cout << "Enter your choice: ";
		cin >> selection;

		switch (selection)
		{
		case '1':	return 0;
			break;

		case '2':	return 1;
			break;
		}
	} while(selection != 2);
}