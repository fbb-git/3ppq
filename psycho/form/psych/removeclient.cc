#include "psych.ih"

Psych::DisplayInfo Psych::removeClient()
{
    uint16_t idx = validClientIdx();

//    g_log << "Remove client" << endl;

    d_client.erase(d_client.begin() + idx);

    return  {
                s_add + s_addActive,
                d_client.size()
            };
}
