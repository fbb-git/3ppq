#include "psych.ih"

void Psych::requireEqual(char const *name, string const &required)
{
    if (d_cgi->param1(name) != required)
        throw false;
}
