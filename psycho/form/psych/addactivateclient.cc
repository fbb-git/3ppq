#include "psych.ih"

Psych::DisplayInfo Psych::addActivateClient()
{
    pushClient();

    inviteClient(d_client.back());

    return  {
                s_update + s_deactivate + s_remove,
                d_client.size() - 1
            };


}




