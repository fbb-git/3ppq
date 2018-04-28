#include "psych.ih"

Psych::DisplayInfo Psych::showClient()
{
//    uint32_t active= validClientData();

    uint16_t idx = validClientIdx();

    string const &action = d_client[idx].active() ? s_deactivate : s_activate;

    return  {
                s_update + action + s_remove,
                idx
            };
}




