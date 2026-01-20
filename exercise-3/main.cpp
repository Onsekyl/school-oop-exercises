#include <iostream>
#include <italianchef.h>

using namespace std;

int getRandomValue(int min, int max)
{
    // Unix timestamp for the randomisation seed
    srand(time(NULL));

    return rand() % max + min;
}

int main()
{
    Chef jimTheChef("Jim");
    jimTheChef.makeSalad(getRandomValue(3, 20));
    jimTheChef.makeSoup(getRandomValue(2, 27));
    cout << endl;

    ItalianChef jeffTheChef("Jeff");
    jeffTheChef.makeSalad(getRandomValue(4, 23));
    jeffTheChef.askSecret("password", 15, 20);
    jeffTheChef.askSecret("pizza", getRandomValue(3, 29), getRandomValue(1, 35));
    cout << endl;

    return 0;
}

