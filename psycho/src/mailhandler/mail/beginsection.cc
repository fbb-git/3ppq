#include "mail.ih"

string Mail::beginSection()
{
    string line;
    if (getline(cin, line))
    {
        clientFields(line);
        if (getline(cin, line) && String::trim(line) == s_end)
            return line;
    }
    mail(s_end + " marker missing"s);
}
