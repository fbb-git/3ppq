#include "wipdata.ih"

WIPdata::WIPdata(uint16_t psychID, uint16_t clientID, Type type)
:
    d_psychID(psychID),
    d_clientID(clientID),
    d_start(time(0))
{
    string name = path();

    LockStream io{ name };
    LockGuard lg = io.lg();

    if (type == UPDATE)
    {
        io.open();
        read(io);
        return;
    }

    for (auto &login: d_otherLogin)
        login = Tools::random(1000, 9999);

    d_selfRatings.resize(Tools::N_QUESTIONS);
    d_metaRatings.resize(Tools::N_QUESTIONS);

    for (auto &ratings: d_otherRatings)
        ratings.resize(Tools::N_QUESTIONS);

    if (Tools::exists(name))
        throw Exception{} << name << " already exists";

    io.open();
    write(io);
}
