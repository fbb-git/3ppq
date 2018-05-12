#include "psych.ih"

void Psych::process()
try
{
g_log << "Psych: state: " << d_cgi->param1("state") << 
        ", e-mail: " << d_cgi->param1("email") << 
        ", show: " << d_cgi->param1("show") << endl;

    auto iter = s_state.find(d_cgi->param1("state")); 
    if (iter == s_state.end())
        throw false;

    (this->*(iter->second))();
}
catch (bool failed)
{
    d_display.homePage();
}













