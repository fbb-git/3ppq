#include "psych.ih"

ClientPage::Info Psych::deactivateClient()
{
    PsychClient *client = validClientData();

    if (client == 0)
        throw Tools::NO_CLIENT;

    if (WIPdata::exists(d_ID, client->ident()))
    {
        WIPdata::remove(d_ID, client->ident());
        g_log << d_ID << '.' << client->ident() << " ABORTED" << endl;
    }
    else
        g_log << "deactivate: no WIPdata " << 
                  d_ID << '.' << client->ident() << endl;

    client->deactivate();

    return  {
                s_update + s_activate + s_remove,
                static_cast<size_t>(client - &d_client.front())
//                s_add + s_addActive,
//                d_client.size()
            };
}




