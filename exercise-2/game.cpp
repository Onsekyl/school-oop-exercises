#include "game.h"

int maxNumber, randomNumber, numOfGuesses = 0;

Game::Game(int maxNum)
{
    cout << "GAME CONSTRUCTOR: Object initialized with a maxNum as " << maxNum << endl;
    maxNumber = maxNum;
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: Object cleared from the stack memory" << endl;
}

void Game::play()
{
    cout << "GAME: Starting the game" << endl;

    int playerGuess = 0;

    // Unix timestamp for the randomisation seed
    srand(time(NULL));

    // '% value' is the upper and '+ value' is the lower limit
    randomNumber = rand() % maxNumber + 1;

    while (playerGuess != randomNumber)
    {
        numOfGuesses++;

        cout << "Guess an integer number between 1 - " << maxNumber << endl;
        cin >> playerGuess;

        // If the input was invalid (wasn't integer or was over boundaries)
        if (cin.fail())
        {
            // Clears error flags
            cin.clear();

            // Drop the rest of the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Really funny. ";
            continue;
        }

        if (playerGuess < randomNumber)
        {
            cout << "Number is larger than " << playerGuess << endl;
        }
        else if (playerGuess > randomNumber)
        {
            cout << "Number is smaller than " << playerGuess << endl;
        }

        cout << endl;
    }

    printGameResult();
}

void Game::printGameResult()
{
    cout << "GAME: Game has ended" << endl
    << "Correct! Number was = " << randomNumber << endl
    << "It took you " << numOfGuesses << " guesses" << endl;
}
