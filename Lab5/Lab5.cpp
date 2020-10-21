#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Wrong_Guess();
void Success_Message();
bool New_Game_Menu();
void Score_Board(int wins, int losses, int numOfGames);

int main() {
	bool gameLoop = true;
	bool programLoop = true;
	int wins{ 0 };
	int losses{0};
	int numOfGames{0};

	//Outer do while controls if a new game is executed or not with a boolean value controled do-while conditon.
	do {
		Score_Board(wins, losses, numOfGames);

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
		while (numOfGuesses <= 10 && gameLoop) {
			if (guess != ranNum) {
				++numOfGuesses;
				Wrong_Guess();
				cout << "Try again: ";
				cin >> guess;
			}
			else {
				++wins;
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
		if (numOfGuesses > 10) {
			++losses;
			cout << "\n\nSorry, you're out of guesses!\n\n";
			if (New_Game_Menu() == 1) {
				programLoop = true;
			}
			else
				programLoop = false;
		}
		++numOfGames;
	} while (programLoop); //Starts new game if true - ends program if false.

	cout << "\n\nFinal stats: \n";

	Score_Board(wins, losses, numOfGames);

	cout << "\n\nGoodbye...\n\n";

	return 0;
}

void Wrong_Guess() {
	int failureMessageIndex{}; //Used to generate random success messages in the if-else ladder below

	srand(unsigned int(time(NULL))); //Seeds random number generator
	failureMessageIndex = rand() % 4 + 1; //Generates random numbers between 0 and 5

	if (failureMessageIndex == 1) {
		cout << "\n\nNope\n\n";
	}
	else if (failureMessageIndex == 2) {
		cout << "\n\nThat's not it.\n\n";
	}
	else if (failureMessageIndex == 3) {
		cout << "\n\nKeep trying.\n\n";
	}
	else if (failureMessageIndex == 4) {
		cout << "\n\nKeep going\n\n";
	}
	else if (failureMessageIndex == 5) {
		cout << "\n\nTough luck this time\n\n";
	}
}

void Success_Message() {
	int successMessageIndex{}; //Used to generate random failure messages in the if-else ladder below

	srand(unsigned int(time(NULL))); //Seeds random number generator
	successMessageIndex = rand() % 4 + 1; //Generates random numbers between 0 and 5

	if (successMessageIndex == 1) {
		cout << "\n\n!!!!!!!!!!!\n";
		cout << "Good job!";
		cout << "\n!!!!!!!!!!!\n";
	}
	else if (successMessageIndex == 2) {
		cout << "\n\n!!!!!!!!!!!\n";
		cout << "That's it!";
		cout << "\n!!!!!!!!!!!\n";
	}
	else if (successMessageIndex == 3) {
		cout << "\n\n!!!!!!!!!!!\n";
		cout << "You got it right!";
		cout << "\n!!!!!!!!!!!\n\n";
	}
	else if (successMessageIndex == 4) {
		cout << "\n\n!!!!!!!!!!!\n";
		cout << "Nice!";
		cout << "\n!!!!!!!!!!!\n";
	}
	else if (successMessageIndex == 5) {
		cout << "\n\n!!!!!!!!!!!\n";
		cout << "Excelsior";
		cout << "\n!!!!!!!!!!!\n";
	}
}

bool New_Game_Menu() {
	char choice; //Stores user's selection in menu
	bool switchLoop = true;
	bool newGame{}; //Stores return value of function - used to determine if new game is initiated or user terminates program. 

	do {
		cout << "\n\n\nPlease make a selection from the menu below:\n";
		cout << "New Game - 1\n";
		cout << "Quit Program - 2\n";

		cout << "Enter your choice: ";
		cin >> choice;
		cout << "\n\n"; //Space before next game.

		switch (choice) {
		case '1':	newGame = true;
			switchLoop = false;
			break;

		case '2':	newGame = false;
			switchLoop = false;
			break;

		default:	cout << "Invaild choice try agian: ";
			break;
		}
	} while (switchLoop);

	return newGame;
}

void Score_Board(int wins, int losses, int numOfGames) {
	cout << "#################\n";
	cout << "Stats so far: \n";
	cout << "Number of games: " << numOfGames << endl;
	cout << "Games won: " << wins << endl;
	cout << "Games lost: " << losses << endl;
	cout << "#################\n";
}