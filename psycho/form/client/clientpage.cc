#include "client.ih"

void Client::clientPage(WIPdata &wipData)
{
//    g_log << "client page starts, self[0] = " << 
//               (int)wipData.selfRatings().front() <<
//            endl;

    if (wipData.selfRatings().front() == 0)         // no self ratings yet
        selfRatings(wipData);

    else if (wipData.metaRatings().front() == 0)   // no meta ratings yet
        metaRatings(wipData);

    else 
        throw false;
}
