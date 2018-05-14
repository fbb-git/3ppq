#include "wipdata.ih"

void WIPdata::write(ostream &out) const
{
    Tools::writeN(out, &d_psychID);

    out << d_clientIdent << '\n';

    Tools::writeN(out, &d_start);
    Tools::writeN(out, &d_clientLogin);

    for (auto login: d_otherLogin)
        Tools::writeN(out, &login);

    
    Tools::writeN(out, d_selfRatings);
    Tools::writeN(out, d_metaRatings);
    
    for (auto const &ratings: d_otherRatings)
        Tools::writeN(out, ratings);

    string iv{ Tools::iv() };
    Tools::writeN(out, iv);

    ostringstream txt;

    Tools::writeN(txt, &d_gender);
    txt << d_clientName << '\n' << 
           d_psychEmail << '\n';

    for (auto const &mail: d_otherEmail)
        txt << mail << '\n';

    string encrypted = Tools::encrypt(iv, txt.str());
    uint16_t size = encrypted.size();

    Tools::writeN(out, &size);
    Tools::writeN(out, encrypted);

    if (out.good())
        return;

    g_log << "writing WIPdata failed" << endl;
    throw Tools::NO_DATA;
}
