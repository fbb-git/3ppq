#include "psychologist.ih"

string Psychologist::encrypt(string const &iv)
{
    Private priv = fillPrivate();

    return Tools::encrypt(iv, privateData());    
}
