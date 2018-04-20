#include "tools.ih"

// static 
size_t Tools::readN(std::istream &in, std::string &dest, size_t nToRead)
{
    dest.resize(nToRead);
    in.clear();
    return in.read(&dest.front(), nToRead).gcount();
}
