#include "psych.ih"

ClientPage::Info Psych::removeClient()
{
    PsychClient *client = validClientData();

    if (client == 0)
        throw Tools::NO_CLIENT;

    WIPdata::remove(d_ID, client->ident());
    Tools::stdLog() << "Remove client " << d_ID << ' ' << client->ident() << 
                                                                        endl;

    d_client.erase( d_client.begin() + (client - &d_client.front()) );

    return  {
                s_add + s_addActive,
                d_client.size()
            };
}
