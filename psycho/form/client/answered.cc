#include "client.ih"

    // when ratings are already available, then throw DATA_AVAILABLE,
    // resulting in an error page being shown.

void Client::answered()
{
    WIPdata wipData{ d_cgi.param1("pid"), d_cgi.param1("cid") };

    LockGuard lg = wipData.read();
    
    std::string const &ratings = d_cgi.param1("ratings");

    size_t type = stoul(d_cgi.param1("ratingType"));

//g_log << "Client::answered: ratingType = " << type << endl;
//g_log << "           received rating 0 = " << (int)ratings.front() << endl;
//g_log << "               self rating 0 = " << (int)wipData.selfRatings().front() << endl;
//g_log << "               meta rating 0 = " << (int)wipData.metaRatings().front() << endl;

    if (type >= s_completedSize)
        throw Tools::DATA_AVAILABLE;

                                    // self-, meta-, otherCompleted
    (this->*s_completed[type])(wipData, ratings);
}


