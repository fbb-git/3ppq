#include "wipdata.ih"

void WIPdata::write(ostream &out) const
{
    Tools::writeN(out, &d_psychID);
    Tools::writeN(out, &d_clientID);
    Tools::writeN(out, &d_start);
    Tools::writeN(out, &d_flags);
    Tools::writeN(out, &d_login0);
    Tools::writeN(out, &d_loginClient);
    Tools::writeN(out, &d_loginOther1);
    Tools::writeN(out, &d_loginOther2);
    Tools::writeN(out, &d_loginOther3);

    string iv{ Tools::iv() };
    Tools::writeN(out, iv);

    string encrypted = 
                    Tools::encrypt(
                        iv, 
                        d_other1 + '\n' + d_other2 + '\n' + d_other3 + '\n'
                    );
    uint16_t size = encrypted.size();

    Tools::writeN(out, &size);
    Tools::writeN(out, encrypted);
}
