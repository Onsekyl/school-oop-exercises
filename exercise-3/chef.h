#ifndef CHEF_H
#define CHEF_H

#include <iostream> // Needed for the string datatype

using namespace std;

class Chef
{
public:
    Chef(string);
    ~Chef();
    int makeSalad(int);
    int makeSoup(int);
    string getName();

protected:
    string chefName;
};

#endif // CHEF_H
