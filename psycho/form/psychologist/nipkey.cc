#include "psychologist.ih"

string Psychologist::nipKey() const
{
    return Tools::md5hash(d_cgi.param1("nip"));
}
