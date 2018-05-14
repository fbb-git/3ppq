#include "client.ih"

void Client::selfRatings(WIPdata &wipData, RatingType type, 
                         char const *file, 
                         char const *opening, char const *closing)
{
//    g_log << "self ratings " << type << endl;

    pidCid(wipData);
    d_display.append("ratingType", to_string(type));
    d_display.append("other", "-");

    d_display.out(file, 
        {
            opening,
            s_himHer[wipData.gender()],
            s_hisHer[wipData.gender()],
            s_heShe[wipData.gender()],
            closing,
            s_selfThanks
        }
    );
}
