#include "client.ih"

void Client::selfCompleted(WIPdata &wipData, string const &ratings)
{
    if (wipData.selfRatings().front() != 0)
        throw false;

    wipData.setSelfRatings(ratings);

    clientPage(wipData);                // start the meta-ratings
}
