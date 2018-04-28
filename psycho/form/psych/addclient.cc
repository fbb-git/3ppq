#include "psych.ih"

Psych::DisplayInfo Psych::addClient()
{
    pushClient();

    return  {
                s_update + s_activate + s_remove,
                d_client.size() - 1
            };
}




