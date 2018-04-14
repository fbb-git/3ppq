#include "psych.ih"

bool Psych::pwdMatch() const
{
    return d_pwdHash == Tools::md5hash(d_cgi.param1("pwd"));
}






