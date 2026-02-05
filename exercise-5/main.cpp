#include "follower.h"
#include "notificator.h"

using namespace std;

int main()
{
    Notificator notificator;

    // https://stackoverflow.com/a/56862609
    Follower followerArr[] =
    {{"Jeff"}, {"Alysia"}, {"Joni"}, {"Jack"}, {"Kona"}};

    // Cast to int to remove warning of 'comparing integers of different signs'
    for (int i = 0; i < int(sizeof(followerArr) / sizeof(followerArr[0])); i++)
    {
        notificator.add(&followerArr[i]);
    }

    // Trying to add a follower that's already following
    notificator.add(&followerArr[2]);

    notificator.print();
    notificator.remove(&followerArr[3]);
    notificator.remove(&followerArr[0]);
    notificator.print();
    notificator.remove(&followerArr[4]);

    // Trying to remove a follower who isn't following
    notificator.remove(&followerArr[3]);
    notificator.post("Hello? Is this posting thingy working?");

    notificator.print();
    notificator.add(&followerArr[4]);
    notificator.add(&followerArr[3]);
    notificator.print();
    notificator.post("Why say lot word when few word do trick");

    return 0;
}
