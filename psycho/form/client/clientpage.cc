#include "client.ih"

void Client::clientPage(WIPdata &wipData)
{
    if (wipData.selfRatings().front() == 0)         // no self ratings yet
        selfRatings(wipData, SELF, "selfinstructions.h", "Bent u");

    else if (wipData.metaRatings().front() == 0)   // no meta ratings yet
        selfRatings(wipData, META, "metainstructions.h", "Vinden anderen u");

    else if (not wipData.hasEmail())
        emailRequest(wipData);

    else 
        throw false;
}
