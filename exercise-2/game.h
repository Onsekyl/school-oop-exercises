#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class Game
{
public:
    Game(int);
    ~Game();

    void play();

private:
    void printGameResult();

    int maxNumber, playerGuess, randomNumber, numOfGuesses;
};

#endif // GAME_H
