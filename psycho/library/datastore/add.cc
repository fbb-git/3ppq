#include "datastore.ih"

bool DataStore::add(uint64_t key, string const &data)
{
    fstream out{ open() };

    out.seekp(0, ios::end);

    if (not d_dataIdx.add(key, out.tellp()))
        return false;

    Preamble preamble{ key, data.size(), data.size() };    
    Tools::write(out, &preamble);

    out.write(&data.front(), preamble.available);

    return true;
}
