#include "wipdata.ih"

WIPdata::WIPdata(std::string const &psychMail, 
                      uint16_t psychID, uint16_t clientID, 
                      string const &clientName, bool gender)
:
    d_psychID(psychID),
    d_clientID(clientID),
    d_gender(gender),
    d_clientName(clientName),
    d_start(time(0)),
    d_clientLogin(Tools::random(1000, 9999)),
    d_selfRatings(Tools::N_QUESTIONS, 0),
    d_metaRatings(Tools::N_QUESTIONS, 0),
    d_psychMail(psychMail)
{
    string name = path();

    d_io = LockStream{ name };

    LockGuard lg = d_io.lg();

    if (Tools::exists(name))
        throw Exception{} << name << " already exists";

    for (auto &login: d_otherLogin)
        login = Tools::random(1000, 9999);

    d_selfRatings.resize(Tools::N_QUESTIONS);
    d_metaRatings.resize(Tools::N_QUESTIONS);

    for (auto &ratings: d_otherRatings)
        ratings.resize(Tools::N_QUESTIONS);

    d_io.open();
    write();
}
