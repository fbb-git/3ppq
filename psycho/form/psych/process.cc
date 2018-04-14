#include "psych.ih"

void Psych::process()
{
    if (
        auto iter = s_state.find(d_cgi.param1("state")); 
        iter == s_state.end()
    )
        d_display.out(g_options.html() + "homepage.h"); // no state!
    else
        (this->*(iter->second))();
}
