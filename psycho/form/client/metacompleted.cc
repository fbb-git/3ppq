#include "client.ih"

void Client::metaCompleted(WIPdata &wipData, string const &ratings)
{
    g_log << "meta completed " << (int)wipData.metaRatings().front() << endl;

    if (wipData.metaRatings().front() == 0)
        wipData.setMetaRatings(ratings);

    wipData.write();

    clientPage(wipData);                    // start the e-mail collection
}
