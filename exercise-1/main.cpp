#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int game(int maxNum);

int main()
{
    int gameResult = game(20);
    cout << "Oikea vastaus! Arvauksia: " << gameResult << endl;

    return 0;
}

int game(int maxNum)
{
    int targetNum, guessNum = 0, guessAmount = 0;

    // Unix timestamp for the randomisation seed
    srand(time(NULL));

    // '% value' is the upper and '+ value' is the lower limit
    targetNum = rand() % maxNum + 1;

    while (guessNum != targetNum)
    {
        guessAmount++;

        cout << "Arvaa kokonaisluku: ";
        cin >> guessNum;

        // If the input was invalid (wasn't integer or was over boundaries)
        if (cin.fail())
        {
            // Clears error flags
            cin.clear();

            // Drop the rest of the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Todella hauskaa. ";
            continue;
        }

        if (guessNum < targetNum)
        {
            cout << "Luku on suurempi kuin " << guessNum << endl;
        }
        else if (guessNum > targetNum)
        {
            cout << "Luku on pienempi kuin " << guessNum << endl;
        }

        cout << endl;
    }

    return guessAmount;
}
