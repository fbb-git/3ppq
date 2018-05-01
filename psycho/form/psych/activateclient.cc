#include "psych.ih"

Psych::DisplayInfo Psych::activateClient()
{
//    uint32_t active= validClientData();

    uint16_t idx = validClientIdx();

    rmExistingWIPdata(d_client[idx], "renewed");

    inviteClient(d_client[idx]);
    
    return  {
                s_update + s_deactivate + s_remove,
                idx
            };
}




