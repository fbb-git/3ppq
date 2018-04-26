#include "client.ih"

void Client::metaCompleted(WIPdata &wipData, string const &ratings)
{
    if (wipData.metaRatings().front() != 0)
        throw false;

    wipData.setMetaRatings(ratings);

    clientPage(wipData);                    // start the e-mail collection
}
