#include "wipdata.ih"

void WIPdata::read(istream &out)
{
    Tools::readN(out, &d_psychID);
    Tools::readN(out, &d_clientID);
    Tools::readN(out, &d_start);
    Tools::readN(out, &d_flags);
    Tools::readN(out, &d_login0);
    Tools::readN(out, &d_loginClient);
    Tools::readN(out, &d_loginOther1);
    Tools::readN(out, &d_loginOther2);
    Tools::readN(out, &d_loginOther3);

    string iv;
    Tools::readN(out, iv, Tools::KEY_SIZE);

    uint16_t size;
    Tools::readN(out, &size);

    string encrypted;
    Tools::readN(out, encrypted, size);

    istringstream addresses{ Tools::decrypt(iv, encrypted) };
    getline(addresses, d_other1);
    getline(addresses, d_other2);
    getline(addresses, d_other3);
}
