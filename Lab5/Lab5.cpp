#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Wrong_Guess();
void Success_Message();
bool New_Game_Menu();

int main() {
	bool gameLoop = true;
	bool programLoop = true;


	//Outer do while controls if a new game is executed or not with a boolean value controled do-while conditon.
	do {

		int numOfGuesses = 1; //Resets guess count to one every iteration.
		int ranNum{}; //Random number is reinitialized to guarantee a new random number from the last game.
		int guess{}; //Stores user's guess.

		srand(unsigned int(time(NULL))); //Seeds random number generator
		ranNum = rand() % 10 + 1; //Generates random numbers between 0 and 100

		cout << "The computer has generated a random number between 0 and 100 inclusive\n";
		cout << "You have 20 tries to guess the random number.\n";
		cout << "Enter your first guess: ";
		cin >> guess;

		gameLoop = true; //Allows for repeat games
		//This while loop represents one game.
		while (numOfGuesses <= 20 && gameLoop) {
			if (guess != ranNum) {
				Wrong_Guess();
				cout << "Try again: ";
				cin >> guess;
			}
			else {
				Success_Message();
				if (New_Game_Menu() == 1) {
					gameLoop = false;
					programLoop = true;
				}
				else {
					gameLoop = false;
					programLoop = false;
				}
			}
		}
		if (numOfGuesses > 20) {
			cout << "Sorry, you're out of guesses!\n\n";
			if (New_Game_Menu() == 1) {
				programLoop = true;
			}
			else
				programLoop = false;
		}
	} while (programLoop); //Starts new game if true - ends program if false.

	cout << "\n\nGoodbye...\n\n";

	return 0;
}

void Wrong_Guess() {
	int failureMessageIndex{}; //Used to generate random success messages in the if-else ladder below

	srand(unsigned int(time(NULL))); //Seeds random number generator
	failureMessageIndex = rand() % 4 + 1; //Generates random numbers between 0 and 5

	if (failureMessageIndex == 1) {
		cout << "Nope\n";
	}
	else if (failureMessageIndex == 2) {
		cout << "That's not it.\n";
	}
	else if (failureMessageIndex == 3) {
		cout << "Keep trying.\n";
	}
	else if (failureMessageIndex == 4) {
		cout << "Keep going\n";
	}
	else if (failureMessageIndex == 5) {
		cout << "Tough luck this time\n";
	}
}

void Success_Message() {
	int successMessageIndex{}; //Used to generate random failure messages in the if-else ladder below

	srand(unsigned int(time(NULL))); //Seeds random number generator
	successMessageIndex = rand() % 4 + 1; //Generates random numbers between 0 and 5

	if (successMessageIndex == 1) {
		cout << "Good job!\n";
	}
	else if (successMessageIndex == 2) {
		cout << "That's it!\n";
	}
	else if (successMessageIndex == 3) {
		cout << "You got it right!\n";
	}
	else if (successMessageIndex == 4) {
		cout << "Nice!\n";
	}
	else if (successMessageIndex == 5) {
		cout << "Excelsior\n";
	}
}

bool New_Game_Menu() {
	char choice; //Stores user's selection in menu
	bool newGame{}; //Stores return value of function - used to determine if new game is initiated or user terminates program. 

	cout << "\n\n\nPlease make a selection from the menu below:\n";
	cout << "New Game - 1\n";
	cout << "Quit Program - 2\n\n";

	cout << "Enter your choice: ";
	cin >> choice;

	switch (choice) {
	case '1':	newGame = true;
		break;

	case '2':	newGame = false;
		break;
	}

	return newGame;
}