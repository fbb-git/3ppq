#include "psych.ih"

ClientPage::Info Psych::addClient()
{
    if (pushClient())
        rmExistingWIPdata(d_client.back(), "removed");

    return  {
//                s_update + s_activate + s_remove,
//                d_client.size() - 1
                s_add + s_addActive,
                d_client.size()         // clear the page
            };
}




