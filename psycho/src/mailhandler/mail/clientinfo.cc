#include "mail.ih"

void Mail::clientInfo()
{
    string line;
    while (getline(cin, line))
    {
        if (String::trim(line) == s_begin)
            return beginSection();
    }

    mailError(s_begin + " section not found"s);
}
