#include "psychclient.ih"

string PsychClient::toString() const
{
    ostringstream out;

    Tools::writeN(out, &d_gender, 1);
    out <<  d_ident     << '\n' <<
            d_name      << '\n' <<
            d_lastName  << '\n' <<
            d_email     << '\n';

    string iv = Tools::iv();
    string enc = Tools::encrypt(iv, out.str());

    out = ostringstream{};

    Tools::writeN(out, iv);
    Tools::writeN(out, &d_ID);
    Tools::writeN(out, &d_active);

    return out.str() + enc;
}
