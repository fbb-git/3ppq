#include "wipdata.ih"

WIPdata::WIPdata(char const  *csvFile, char const *psychEmail, bool gender,
                char const *clientName)
:
    d_gender(gender),
    d_clientName(clientName),
    d_otherLogin{0, },
    d_psychEmail(psychEmail)
{
    Ratings ratings{ csvFile };

    d_psychID = stoul(ratings.psychID());
    d_clientIdent = ratings.clientIdent();
    d_start = ratings.from();

    assign(d_selfRatings,     ratings.data()[0]);
    assign(d_metaRatings,     ratings.data()[1]);
    assign(d_otherRatings[0], ratings.data()[2]);

    for (size_t idx = 1; idx != Tools::N_OTHER; ++idx)
        d_otherRatings[idx] = d_otherRatings[0];
}

