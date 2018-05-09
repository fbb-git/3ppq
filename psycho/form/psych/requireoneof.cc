#include "psych.ih"

void Psych::requireOneOf(char const *name, char const *charSet)
{
    if (size_t pos = 0; 
                (pos = d_cgi->param1(name).find_first_of(charSet))
                == string::npos
            ||
                d_cgi->param1(name).find_first_of(charSet, pos + 1)
                != string::npos
    )
        throw false;
}
