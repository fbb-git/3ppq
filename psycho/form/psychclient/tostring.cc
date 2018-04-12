#include "psychclient.ih"

string PsychClient::toString() const
{
    ostringstream out;

    Tools::writeN(out, &d_gender, 1);
    out <<  d_name      << '\n' <<
            d_lastName  << '\n' <<
            d_email     << '\n';

    string iv = Tools::iv();
    string enc = Tools::encrypt(iv, out.str());

    out = ostringstream{};

    Tools::write(out, iv);
    Tools::writeN(out, &d_ID);

    return out.str() + enc;
}
