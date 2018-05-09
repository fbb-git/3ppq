#include "psychclient.ih"

void PsychClient::get(string const &data)
{
    istringstream in(data);

    string iv(8, 0);
    Tools::readN(in, &iv.front(), 8);

    Tools::readN(in, &d_ID);
    Tools::readN(in, &d_active);

    ostringstream out;
    out << in.rdbuf();

    in.str(Tools::decrypt(iv, out.str()));

    Tools::readN(in, &d_gender, 1);
    getline(in, d_ident);
    getline(in, d_name);
    getline(in, d_lastName);
    getline(in, d_eMail);
}
