
#include "client.ih"

    // when ratings are already available, then throw false, resulting in
    // the /index.html page being shown.

void Client::answered()
{
    WIPdata wipData{ d_cgi.param1("pid"), d_cgi.param1("cid") };

    LockGuard lg = wipData.read();
    
    std::string const &ratings = d_cgi.param1("ratings");

    size_t type = stoul(d_cgi.param1("ratingType"));
    if (type >= s_completedSize)
        throw false;
                                    // self-, meta-, otherCompleted
    (this->*s_completed[type])(wipData, ratings);
}


