#include "datastore.ih"

DataStore::DataStore(string const &path)
:
    d_stream(path),
    d_dataIdx(path + ".idx")
{
    uint16_t next = 0;

    LockGuard lck{ lg() };

    d_stream.open();

    if (Tools::readN(d_stream, &next) == 0)     // file empty ?
        Tools::writeN(d_stream, &next);         // store next available nr.

}
