/*
Not sure if I should include the handling of edge cases on this branch
because they weren't really required and would make code more complicated to read
(I don't know how teachers review the exercises).
For now I made a separate branch for them: exercise-5-edgecases
*/

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

    notificator.print();
    notificator.remove(&followerArr[3]);
    notificator.remove(&followerArr[0]);
    notificator.print();
    notificator.remove(&followerArr[4]);
    notificator.post("Hello? Is this posting thingy working?");

    notificator.print();
    notificator.add(&followerArr[4]);
    notificator.add(&followerArr[3]);
    notificator.print();
    notificator.post("Why say lot word when few word do trick");

    return 0;
}
