#include "client.ih"

void Client::process()
{
    auto iter = s_state.find(d_cgi.param1("state")); 

    if (iter == s_state.end())
        throw Tools::NO_STATE;

    (this->*(iter->second))();
}
