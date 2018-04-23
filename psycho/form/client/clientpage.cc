#include "client.ih"

bool Client::clientPage(WIPdata &wipData)
{
    g_log << "client page starts, self[0] = " << 
               (int)wipData.selfRatings().front() <<
            endl;

    if (wipData.selfRatings().front() == 0)         // to do: self ratings
        return selfRatings(wipData);

    if (wipData.metaRatings().front() == 0)         // to do: meta ratings
    {
        metaRatings(wipData);
        return true;
    }

    trySaveData();                                  // active -> 0, save
    return false;
}
