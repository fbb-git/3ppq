#include "wipdata.ih"

WIPdata::WIPdata(std::string const &psychEmail, 
                      uint16_t psychID, string const &clientIdent, 
                      string const &clientName, bool gender)
:
    d_psychID(psychID),
    d_clientIdent(clientIdent),
    d_gender(gender),
    d_clientName(clientName),
    d_start(time(0)),
    d_clientLogin(Tools::random(1000, 9999)),
    d_selfRatings(Tools::N_QUESTIONS, 0),
    d_metaRatings(Tools::N_QUESTIONS, 0),
    d_psychEmail(psychEmail)
{
    string name = path();

    d_io = LockStream{ name };

    LockGuard lg = d_io.lg();

    if (Tools::rwExists(name))
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




