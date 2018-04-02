#include "datastore.ih"

std::fstream DataStore::open()
{
    fstream ret{ d_path, ios::in | ios::out };

    if (not ret)
        Exception::open(ret, d_path, ios::in | ios::trunc | ios::out);

    return ret;
}
