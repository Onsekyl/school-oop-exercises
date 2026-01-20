#include "chef.h"

Chef::Chef(string name)
{
    cout << "CHEF CONSTRUCTOR: Initialized with " << name << " as a chefName" << endl;
    chefName = name;
}

Chef::~Chef()
{
    cout << "CHEF DESTRUCTOR: " << chefName << endl;
}

int Chef::makeSalad(int ingredientAmount)
{
    int saladAmount = ingredientAmount / 5;

    cout << chefName << "'s makeSalad() called with " << ingredientAmount << " ingredients. "
         << chefName << " makes " << saladAmount << " salad portions." << endl;

    return saladAmount;
}

int Chef::makeSoup(int ingredientAmount)
{
    int soupAmount = ingredientAmount / 3;

    cout << chefName << "'s makeSoup() called with " << ingredientAmount << " ingredients. "
         << chefName << " makes " << soupAmount << " soup portions." << endl;

    return soupAmount;
}

string Chef::getName()
{
    cout << chefName << "'s getName() called" << endl;
    return chefName;
}
