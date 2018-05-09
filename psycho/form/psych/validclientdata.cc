#include "psych.ih"

PsychClient &Psych::validClientData()
{
    PsychClient &client = d_client[validClientIdx()];

    requireEqual("ident",    client.ident());
    requireEqual("name",     client.name());
    requireEqual("lastName", client.lastName());
    requireEqual("clEmail",  client.eMail());

    return client;
}

