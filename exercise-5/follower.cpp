#include "follower.h"
#include <iostream>

using namespace std;

Follower::Follower(string followerName)
{
    cout << "[FOLLOWER CONSTRUCTOR] New follower with a name: " << followerName << '\n';
    name = followerName;
}

string Follower::getName()
{
    // I don't think this is necessary, it just makes the prints confusing
    // cout << "Getting the follower's name: " << name << '\n';
    return name;
}

void Follower::receivePost(string post)
{
    cout << name << " received a post: " << post << '\n';
}
