#include "psych.ih"

string Psych::emailKey() const
{
    return Tools::md5hash(d_cgi.param1("email"));
}
