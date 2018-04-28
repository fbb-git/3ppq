#include "psych.ih"

Psych::DisplayInfo Psych::deactivateClient()
{
//    uint32_t active= validClientData();

    uint16_t idx = validClientIdx();

    d_client[idx].deactivate();

    return  {
                s_update + s_activate + s_remove,
                idx
            };
}




