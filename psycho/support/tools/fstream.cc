#include "tools.ih"

// static
fstream Tools::fstream(std::string const &path)
{
    std::fstream ret{ path, ios::in | ios::out };

    if (not ret)
        Exception::open(ret, path, ios::in | ios::out | ios::trunc);

    return ret;
}
