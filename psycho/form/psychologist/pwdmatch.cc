#include "psychologist.ih"

bool Psychologist::pwdMatch(Record const &record) const
{
    return record.pwdHash == Tools::md5hash(d_cgi.param1("pwd"));
}
