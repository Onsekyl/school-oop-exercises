#include "follower.h"
#include "notificator.h"
#include <iostream>

using namespace std;

int main()
{
    Notificator notificator;
    Follower follower1("Jeff");

    notificator.add(&follower1);
    return 0;
}
