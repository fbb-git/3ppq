#include "psych.ih"

// static
string Psych::newPassword()
{
    string ret;

    while (ret.size() != 6)
    {
        int ch = Tools::random(127);
        if (isprint(ch))
            ret += ch;
    }

    return ret;
}
