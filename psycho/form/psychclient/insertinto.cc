#include "psychclient.ih"

ostream &PsychClient::insertInto(ostream &out) const
{
    return out <<
        "           Initials and name: " << d_name.length() << ' ' << 
                                            d_lastName << "\n"
        "                      gender: " << d_gender << "\n" 
        "                      e-mail: " << d_eMail << "\n"
        "                       ident: " << d_ident << "\n"
        "                      active: " << d_active << "\n" 
        "                          ID: " << d_ID;
}
