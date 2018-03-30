#include "psychologist.ih"

void Psychologist::process()
{
    if (
        auto iter = s_state.find(d_cgi.param1("state")); 
        iter == s_state.end()
    )
        Display{ "homepage" };          // unknown state? weird: go home...
    else
        (this->*(iter->second))();
}
