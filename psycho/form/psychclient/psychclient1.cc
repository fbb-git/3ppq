#include "psychclient.ih"

PsychClient::PsychClient(uint16_t ID, bool gender, string const &name, 
                        string const &lastName, string const &email)
:
    d_ID(ID),
    d_gender(gender),
    d_name(name),
    d_lastName(lastName),
    d_email(email)
{}
