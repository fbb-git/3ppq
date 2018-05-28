#include "psych.ih"

ClientPage::Info Psych::showClient()
{
    size_t idx = validClientIdx();

    if (idx == d_client.size())
        throw Tools::NO_CLIENT;

    PsychClient &client = d_client[idx];

    string const &action = client.active() ? s_deactivate : s_activate;

    return  {
                s_update + action + s_remove,
                idx
            };
}




