#include "client.ih"

void Client::metaRatings(WIPdata &wipData)
{
    g_log << "meta ratings" << endl;


    pidCid(wipData);
    d_display.append("ratingType", to_string(META));
    d_display.out("instructionsmeta.h",
        {
            "Vinden anderen u"
        }
    );
}
