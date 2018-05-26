#include "client.ih"

void Client::clientPage(WIPdata &wipData)
{
//    g_log << "clientPage: " << (int)wipData.selfRatings().front() << endl;
//    g_log << "            " << (int)wipData.metaRatings().front() << endl;

    if (wipData.selfRatings().front() == 0)         // no self ratings yet
        selfRatings(
            wipData, SELF, "selfinstructions.h", "Bent u", s_closeSelf
        );

    else if (wipData.metaRatings().front() == 0)   // no meta ratings yet
        selfRatings(
            wipData, META, "metainstructions.h", "Vinden anderen u", 
            s_closeMeta
        );

    else if (not wipData.hasEmail())
        emailRequest(wipData);

    else 
        throw Tools::DATA_AVAILABLE;
}
