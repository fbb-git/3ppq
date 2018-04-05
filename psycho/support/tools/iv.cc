#include "tools.ih"

// static
std::string Tools::iv()
{
    string ret(8, '\0');

    for (size_t idx = 0; idx != 8; ++idx)
        ret[idx] = random(255);

    return ret;
}
