#include "psych.ih"

long long Psych::requireNumber(char const *name)
try
{
    return stoll(d_cgi->param1(name));
}
catch (...)
{
    g_log << "cgi param " << name << " `" << d_cgi->param1(name) << 
                                            "': NaN" << endl;

    throw Tools::REQUIRE;
}
