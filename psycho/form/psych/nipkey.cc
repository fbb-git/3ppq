#include "psych.ih"

string Psych::nipKey() const
{
    return Tools::md5hash(d_cgi.param1("nip"));
}
