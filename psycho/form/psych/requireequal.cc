#include "psych.ih"

void Psych::requireEqual(char const *name, string const &required)
{
    if (d_cgi->param1(name) == required)
        return;

    g_log << "cgi param " << name << " `" << d_cgi->param1(name) << 
             "' not equal " << required << endl;

    throw false;
}
