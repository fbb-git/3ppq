#include "psych.ih"

ClientPage::Info Psych::addActivateClient()
{
    if (pushClient())
    {
        rmExistingWIPdata(d_client.back(), "removed");
        inviteClient(d_client.back());
    }

    return  {
                //s_update + s_deactivate + s_remove,
                //d_client.size() - 1
                s_add + s_addActive,
                d_client.size()
            };


}




