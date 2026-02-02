#ifndef NOTIFICATOR_H
#define NOTIFICATOR_H

#include "follower.h"
#include <string>

class Notificator
{
public:
    Notificator();
    void add(Follower*);
    void remove(Follower*);
    void print();
    void post(std::string);

private:
    Follower* followers = nullptr;
};

#endif // NOTIFICATOR_H
