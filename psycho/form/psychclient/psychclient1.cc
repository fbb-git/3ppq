#include "psychclient.ih"

PsychClient::PsychClient(uint16_t ID, uint32_t active, uint8_t login0, 
                        bool gender, string const &name, 
                        string const &lastName, string const &email)
:
    d_ID(ID),
    d_active(active),
    d_login0(login0),
    d_gender(gender),
    d_name(name),
    d_lastName(lastName),
    d_email(email)
{}
