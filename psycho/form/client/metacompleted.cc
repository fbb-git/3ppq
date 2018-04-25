#include "client.ih"

void Client::metaCompleted(WIPdata const &wipData, string const &ratings)
{
    if (wipData.metaRatings.front() != 0)
    {
        obtainEmail(wipData);
        return;
    }   

    wipData.setMetaRatings(ratings);

    pidCid(wipData);

    d_display.append("ratingType", to_string(META));

    d_display.out("instructionsmeta.h",
        {
            "Vinden anderen u"
        }
    );
}
