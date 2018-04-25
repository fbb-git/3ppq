
#include "client.ih"

    // when ratings are already available, then throw false, resulting in
    // the /index.html page being shown.

void Client::answered()
{
    WIPdata wipData{ d_cgi.param1("pid"), d_cgi.param1("cid") };

    LockGuard lg = wipData.read();
    
    std::string const &ratings = d_cgi.param1("ratings");

    switch (uint16_t type = stoul(d_cgi.param1("ratingType")))
    {
        case SELF:
            selfCompleted(wipData, ratings);
        break;

        case META:
            metaCompleted(wipData, ratings);
        break;

        default:
            type -= OTHER;
            if (type > N_OTHER || wipData.otherRatings[type].front() != 0)
                throw false;
            wipData.setOtherRatings(ratings);
        break;
    }

    checkCompleted(wipData);    // only with others
}


