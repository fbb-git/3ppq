#include "psych.ih"

void Psych::process()
try
{
    auto iter = s_state.find(d_cgi->param1("state")); 
    if (iter == s_state.end())
        throw false;

    (this->*(iter->second))();
}
catch (bool failed)
{
    d_display.homePage();
}













