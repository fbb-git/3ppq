#include "psych.ih"

ClientPage::Info Psych::activateClient()
{
    PsychClient *client = validClientData();

    if (client == 0)
        throw Tools::NO_CLIENT;

    if (client->active() != 0)
        g_log << "client " << client->ID() << 
                    " already active: request ignored" << endl;
    else
        inviteClient(*client);
    
                //    size_t idx = &client - &d_client.front();

    return  {
                //s_update + s_deactivate + s_remove,
                //idx
                s_add + s_addActive,
                d_client.size()         // clear the page
            };
}




