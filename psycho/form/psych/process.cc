#include "psych.ih"

void Psych::process()
{
g_log << "Psych: state: " << d_cgi->param1("state") << 
        ", e-mail: " << d_cgi->param1("email") << 
        ", show: " << d_cgi->param1("show") << endl;

    auto iter = s_state.find(d_cgi->param1("state")); 
    if (iter == s_state.end())
        throw Tools::NO_STATE;

    (this->*(iter->second))();
}













