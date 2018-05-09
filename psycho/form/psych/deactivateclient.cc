#include "psych.ih"

Psych::DisplayInfo Psych::deactivateClient()
{
    PsychClient &client = validClientData();

    if (WIPdata::exists(d_ID, client.ident()))
        WIPdata::remove(d_ID, client.ident());
    else
        Tools::debug() << "deactivate: non-existing wip data " << 
                            d_ID << '.' << client.ident() << endl;

    client.deactivate();

    size_t idx = &client - &d_client.front();

    return  {
                s_update + s_activate + s_remove,
                idx
            };
}




