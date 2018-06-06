#include "psych.ih"

bool Psych::erase()
{
    return d_data.erase(Tools::md5hash(d_eMail));
}
