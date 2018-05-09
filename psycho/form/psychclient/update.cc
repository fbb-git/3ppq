#include "psychclient.ih"

void PsychClient::update(string const &ident,
                         string const &name, string const &lastName,
                         string const &email)
{
    d_ident = ident;
    d_name = name;
    d_lastName = lastName;
    d_eMail = email;
}
