#include "notificator.h"
#include <iostream>

using namespace std;

Notificator::Notificator()
{
    cout << "[NOTIFICATOR CONSTRUCTOR] New notificator\n";
}

void Notificator::add(Follower* follower)
{
    Follower* currentFollower = followers;

    while (currentFollower != nullptr)
    {
        if (currentFollower == follower)
        {
            cout << "[NOTIFICATOR] Can't add follower: " << follower->getName() << " (already following)\n";
            return;
        }

        currentFollower = currentFollower->next;
    }

    cout << "[NOTIFICATOR] Adding follower: " << follower->getName() << '\n';
    follower->next = followers;
    followers = follower;
}

void Notificator::remove(Follower* follower)
{
    if (followers == nullptr)
    {
        cout << "[NOTIFICATOR] Can't remove follower: " << follower->getName() << " (no followers)\n";
        return;
    }
    else if (followers == follower)
    {
        cout << "[NOTIFICATOR] Removing follower: " << followers->getName() << '\n';
        followers = followers->next;
        return;
    }

    Follower* currentFollower = followers;

    while (currentFollower->next != follower)
    {
        if (currentFollower->next == nullptr)
        {
            cout << "[NOTIFICATOR] Can't remove follower: " << follower->getName()
                 << " (not following)\n";
            return;
        }

        currentFollower = currentFollower->next;
    }

    cout << "[NOTIFICATOR] Removing follower: " << currentFollower->next->getName() << '\n';
    currentFollower->next = currentFollower->next->next;
}

void Notificator::print()
{
    Follower* currentFollower = followers;
    int i = 0;

    cout << "\n[NOTIFICATOR] List of followers:\n";

    while (currentFollower != nullptr)
    {
        cout << ++i << ". " << currentFollower->getName() << '\n';
        currentFollower = currentFollower->next;
    }

    cout << '\n';
}

void Notificator::post(string post)
{
    cout << "[NOTIFICATOR] Posting a message: " << post << '\n';

    Follower* currentFollower = followers;

    while (currentFollower != nullptr)
    {
        currentFollower->receivePost(post);
        currentFollower = currentFollower->next;
    }
}
