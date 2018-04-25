#include "client.ih"

void Client::selfCompleted(WIPdata const &wipData, string const &ratings)
{
    if (wipData.selfRatings.front() != 0)
        throw false;

    wipData.setSelfRatings(ratings);

    pidCid(wipData);

    d_display.append("ratingType", to_string(META));

    d_display.out("instructionsmeta.h",
        {
            "Vinden anderen u"
        }
    );
}
