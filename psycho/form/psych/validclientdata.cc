#include "psych.ih"

PsychClient *Psych::validClientData()
{
    size_t idx = validClientIdx();

    if (idx ==  d_client.size())                // no such client
        return 0;

    PsychClient &client = d_client[idx];

    requireEqual("ident",    client.ident());
    requireEqual("name",     client.name());
    requireEqual("lastName", client.lastName());
    requireEqual("clEmail",  client.eMail());

    return &client;                             // return the client's address
}

