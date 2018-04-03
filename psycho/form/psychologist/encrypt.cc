#include "psychologist.ih"

string Psychologist::encrypt(string const &iv) const
{
    return Tools::encrypt(iv, privateData());    
}
