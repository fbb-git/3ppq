#include "client.ih"

void Client::selfCompleted(WIPdata &wipData, string const &ratings)
{
    g_log << "self completed " << (int)wipData.selfRatings().front() << endl;

    if (wipData.selfRatings().front() != 0)
        throw Tools::DATA_AVAILABLE;

    wipData.setSelfRatings(ratings);

    wipData.write();

    clientPage(wipData);                // start the meta-ratings
}
