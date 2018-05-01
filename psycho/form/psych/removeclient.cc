#include "psych.ih"

Psych::DisplayInfo Psych::removeClient()
{
    uint16_t idx = validClientIdx();

    WIPdata::remove(d_ID, d_client[idx].ident());
    Tools::stdLog() << "Remove client " << d_ID << ' ' << 
                       d_client[idx].ident() << endl;

    d_client.erase(d_client.begin() + idx);

    return  {
                s_add + s_addActive,
                d_client.size()
            };
}
