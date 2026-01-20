#ifndef CHEF_H
#define CHEF_H

#include <iostream>

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
