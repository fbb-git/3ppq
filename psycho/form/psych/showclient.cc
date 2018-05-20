#include "psych.ih"

ClientPage::Info Psych::showClient()
{
    PsychClient &client = d_client[validClientIdx()];

    string const &action = client.active() ? s_deactivate : s_activate;

    size_t idx = &client - &d_client.front();

    return  {
                s_update + action + s_remove,
                idx
            };
}




