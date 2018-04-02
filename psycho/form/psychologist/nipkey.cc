#include "psychologist.ih"

uint64_t Psychologist::nipKey() const
{
    return Tools::md5hash8(d_cgi.param1("nip"));
}
