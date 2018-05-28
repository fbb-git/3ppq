#include "psych.ih"

ClientPage::Info Psych::deactivateClient()
{
    PsychClient *client = validClientData();

    if (client == 0)
        throw Tools::NO_CLIENT;

    if (WIPdata::exists(d_ID, client->ident()))
        WIPdata::remove(d_ID, client->ident());
    else
        g_log << "deactivate: non-existing wip data " << 
                  d_ID << '.' << client->ident() << endl;

    client->deactivate();

    return  {
                s_update + s_activate + s_remove,
                static_cast<size_t>(client - &d_client.front())
//                s_add + s_addActive,
//                d_client.size()
            };
}




