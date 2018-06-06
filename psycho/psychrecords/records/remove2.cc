#include "records.ih"

// static
void Records::remove(string const &path)
{
    if (Tools::rwExists(path) && unlink(path.c_str()) != 0)
        throw Exception{} << "can't remove " << path;
}
