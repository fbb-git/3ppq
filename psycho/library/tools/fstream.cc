#include "tools.ih"

// static
fstream Tools::fstream(std::string const &path)
{
    fstream ret{ path, ios::in | ios::out };

    if (not ret)
        Exception::open(ret, ios::in | ios::out | ios::trunc);

    return ret;
}
