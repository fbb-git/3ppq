#include "datastore.ih"

bool DataStore::add(std::string const &key, string const &data)
{
    fstream out{ open() };

    uint64_t size = Tools::size(out);

    if (not d_dataIdx.add(key, size))
        return false;

    Preamble preamble{ key, data.size(), data.size() };
    putPreamble(out, size, preamble);

    out.write(&data.front(), preamble.available);

    return true;
}
