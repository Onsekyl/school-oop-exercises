#include "italianchef.h"

ItalianChef::ItalianChef(string name)
    : Chef(name)
{
    cout << "ITALIANCHEF CONSTRUCTOR: Initialized with a " << name << " as a chefName" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ITALIANCHEF DESTRUCTOR: " << chefName << endl;
}

bool ItalianChef::askSecret(string givenPassword, int flourAmount, int waterAmount)
{
    bool wasCorrectPassword = (givenPassword == password) ? true : false;
    cout << chefName << "'s askSecret() called with " << string(wasCorrectPassword ? "correct" : "incorrect")
         << " password" << endl;

    if (wasCorrectPassword)
    {
        flour = flourAmount;
        water = waterAmount;
        makePizza();
    }

    return wasCorrectPassword;
}

int ItalianChef::makePizza()
{
    int pizzaAmount = min(flour, water) / 5;

    cout << chefName << "'s makePizza() called. Flour amount: " << flour << ", water amount: " << water
         << ". " << chefName << " makes " << pizzaAmount << " pizzas." << endl;

    return pizzaAmount;
}
