#include "psych.ih"

Psych::DisplayInfo Psych::activateClient()
{
//    uint32_t active= validClientData();

    uint16_t idx = validClientIdx();

    d_client[idx].activate();

    return  {
                s_update + s_deactivate + s_remove,
                idx
            };
}




