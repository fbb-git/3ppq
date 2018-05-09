#include "psych.ih"

void Psych::requireContents(char const *name)
{
    if (not Tools::checkParam(*d_cgi, name))
        throw false;
}
