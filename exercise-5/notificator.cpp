#include "notificator.h"
#include <iostream>

using namespace std;

Notificator::Notificator()
{
    cout << "[NOTIFICATOR CONSTRUCTOR] New notificator"
}

void Notificator::add(Follower* follower)
{
    if (followers == nullptr)
    {
        cout << "First follower" << '\n';
    }
}

void Notificator::remove(Follower* follower)
{

}

void Notificator::print()
{

}

void Notificator::post(string post)
{

}
