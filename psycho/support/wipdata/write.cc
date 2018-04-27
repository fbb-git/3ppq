#include "wipdata.ih"

void WIPdata::write() const
{
    d_io.seekp(0);

    Tools::writeN(d_io, &d_psychID);
    Tools::writeN(d_io, &d_clientID);
    Tools::writeN(d_io, &d_start);
    Tools::writeN(d_io, &d_clientLogin);

    for (auto login: d_otherLogin)
        Tools::writeN(d_io, &login);

    
    Tools::writeN(d_io, d_selfRatings);
    Tools::writeN(d_io, d_metaRatings);
    
    for (auto const &ratings: d_otherRatings)
        Tools::writeN(d_io, ratings);

    string iv{ Tools::iv() };
    Tools::writeN(d_io, iv);

    ostringstream txt;

    Tools::writeN(txt, &d_gender);
    txt << d_clientName << '\n' << 
           d_psychEmail << '\n';

    for (auto const &mail: d_otherEmail)
        txt << mail << '\n';

    string encrypted = Tools::encrypt(iv, txt.str());
    uint16_t size = encrypted.size();

    Tools::writeN(d_io, &size);
    Tools::writeN(d_io, encrypted);

    if (not d_io.good())
        throw Exception{} << "writing WIPdata failed";
}
