#include "client.ih"

void Client::process()
{
    if (
        auto iter = s_state.find(d_cgi.param1("state")); 
        iter == s_state.end()
    )
        Display{ g_options.html() + "homepage" };   // no state? weird...
    else
        (this->*(iter->second))();
}
