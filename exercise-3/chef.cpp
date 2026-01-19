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
    cout << chefName << "'s makeSalad() called with " << ingredientAmount << " ingredients" << endl;
    return ingredientAmount / 5;
}

int Chef::makeSoup(int ingredientAmount)
{
    cout << chefName << "'s makeSoup() called with " << ingredientAmount << " ingredients" << endl;
    return ingredientAmount / 3;
}

string Chef::getName()
{
    cout << chefName << "'s getName() called" << endl;
    return chefName;
}
