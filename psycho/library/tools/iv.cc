#include "tools.ih"

// static
std::string Tools::iv()
{
    string ret(16, '\0');

    for (size_t idx = 0; idx != 16; ++idx)
        ret[idx] = random(255);

    return ret;
}
