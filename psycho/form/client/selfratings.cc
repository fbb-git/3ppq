#include "client.ih"

bool Client::selfRatings(WIPdata &wipData)
{
    g_log << "self ratings" << endl;

//                            // verify available e-mail addresses
//    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
//    {
//        g_log << "other mail " << idx << ": `" <<
//            wipData.otherMail(idx) << endl;
//
//        if (wipData.otherMail(idx).empty())
//        {
//            pidCid(wipData);
//            d_display.out("reqemail.h");
//            return true;
//        }
//    }

    selfInstructions(hash, wipData);

    g_log << "self ratings: WIP" << endl;
    return true;
}


