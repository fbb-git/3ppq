#include "psych.ih"

Psych::DisplayInfo Psych::deactivateClient()
{
//    uint32_t active= validClientData();

    uint16_t idx = validClientIdx();

    if (WIPdata::exists(d_ID, d_client[idx].ident()))
        WIPdata::remove(d_ID, d_client[idx].ident());
    else
        Tools::debug() << "deactivate: non-existing wip data " << 
                            d_ID << '.' << d_client[idx].ident() << endl;

    d_client[idx].deactivate();

    return  {
                s_update + s_activate + s_remove,
                idx
            };
}




