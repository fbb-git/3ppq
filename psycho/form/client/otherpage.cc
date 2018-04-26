#include "client.ih"

void Client::otherPage(WIPdata &wipData, size_t idx)
{
    g_log << "other page " << idx << " starts" << endl;

    if (wipData.otherRatings(idx).front() != 0)         // ratings already
        throw false;                                    // available.

    pidCid(wipData);
    d_display.append("ratingType",  to_string(OTHER));
    d_display.append("other",       to_string(idx));

    d_display.out("otherinstructions.h", 
        {
            "Is",
            wipData.clientName()
        }
    );
}
