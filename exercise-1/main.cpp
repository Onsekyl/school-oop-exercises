#include <iostream>
#include <cstdlib>
#include <time.h>

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
    int targetNum, guessNum = -1, guessAmount = 0;

    srand(time(NULL)); // Unix timestamp for the randomisation's seed
    targetNum = rand() % maxNum; // '% value' is the upper limit

    while (guessNum != targetNum)
    {
        guessAmount++;

        cout << "Arvaa luku: ";

        // ?? Should the input accept integer only??
        cin >> guessNum;

        if (guessNum < targetNum)
        {
            cout << "luku on suurempi kuin " << guessNum << endl;
        }
        else if (guessNum > targetNum)
        {
            cout << "luku on pienempi kuin " << guessNum << endl;
        }

        cout << endl;
    }

    return guessAmount;
}
