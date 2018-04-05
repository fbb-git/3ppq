#include "psych.ih"

string Psych::encrypt(string const &iv) const
{
    return Tools::encrypt(iv, privateData());    
}
