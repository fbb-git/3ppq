#include "psych.ih"

bool Psych::get()
{
    if (get(emailKey()))
        return true;

    notRegistered();
    return false;
}




