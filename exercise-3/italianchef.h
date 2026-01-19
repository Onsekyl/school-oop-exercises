#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"

class ItalianChef : public Chef
{
public:
    ItalianChef(string);
    ~ItalianChef();
    bool askSecret(string, int, int);

private:
    string password = "pizza";
    int flour;
    int water;

    int makePizza();
};

#endif // ITALIANCHEF_H
