#include "psychclient.ih"

PsychClient::PsychClient(uint16_t ID, bool gender, string const &ident, 
                        string const &name, string const &lastName, 
                        string const &email)
:
    d_ID(ID),
    d_gender(gender),
    d_ident(ident),
    d_name(name),
    d_lastName(lastName),
    d_eMail(email)
{}
