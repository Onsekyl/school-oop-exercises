#ifndef FOLLOWER_H
#define FOLLOWER_H

#include <string>

class Follower
{
public:
    Follower(std::string);
    std::string getName();
    void receivePost(std::string);

    Follower* next = nullptr;

private:
    std::string name;
};

#endif // FOLLOWER_H
