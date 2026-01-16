#include "game.h"

int randomMaxLimit, targetNum, numOfGuesses = 0;

Game::Game(int maxNum)
{
    cout << "GAME CONSTRUCTOR: Object initialized with a maxNum as " << maxNum << endl;
    randomMaxLimit = maxNum;
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: Object cleared from the stack memory" << endl;
}

void Game::play()
{
    cout << "GAME: Starting the game" << endl;

    int guessNum = 0;

    // Unix timestamp for the randomisation seed
    srand(time(NULL));

    // '% value' is the upper and '+ value' is the lower limit
    targetNum = rand() % randomMaxLimit + 1;

    while (guessNum != targetNum)
    {
        numOfGuesses++;

        cout << "Guess an integer number between 1 - " << randomMaxLimit << endl;
        cin >> guessNum;

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

        if (guessNum < targetNum)
        {
            cout << "Number is larger than " << guessNum << endl;
        }
        else if (guessNum > targetNum)
        {
            cout << "Number is smaller than " << guessNum << endl;
        }

        cout << endl;
    }

    printGameResult();
}

void Game::printGameResult()
{
    cout << "GAME: Game has ended" << endl
    << "Correct! Number was = " << targetNum << endl
    << "It took you " << numOfGuesses << " guesses" << endl;
}
