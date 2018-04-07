#include "psych.ih"

// static
string Psych::newPassword()
{
    string ret;

    while (ret.size() != 6)
    {
                                    // avoid a space as pwd char.
        int ch = ' ' + 1 + Tools::random(127 - (' ' + 1));
        if (isprint(ch))
            ret += ch;
    }

    return ret;
}
