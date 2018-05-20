#include "psych.ih"

ClientPage::Info Psych::activateClient()
{
    PsychClient &client = validClientData();

    rmExistingWIPdata(client, "renewed");

    inviteClient(client);
    
    size_t idx = &client - &d_client.front();

    return  {
                s_update + s_deactivate + s_remove,
                idx
            };
}




