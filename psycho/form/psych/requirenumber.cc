#include "psych.ih"

long long Psych::requireNumber(char const *name)
try
{
    return stoll(d_cgi->param1(name));
}
catch (...)
{
    throw false;
}
