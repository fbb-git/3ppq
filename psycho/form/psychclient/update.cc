#include "psychclient.ih"

void PsychClient::update(string const &name, string const &lastName,
                         string const &email)
{
    d_name = name;
    d_lastName = lastName;
    d_email = email;
}
