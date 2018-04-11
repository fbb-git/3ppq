#include "datastore.ih"

bool DataStore::add(std::string const &key, string const &data)
{
    d_stream.open();

    uint64_t size = Tools::size(d_stream);

    if (not d_dataIdx.add(key, size))
        return false;

    Preamble preamble{ key, data.size(), data.size() };
    putPreamble(size, preamble);

    d_stream.write(&data.front(), preamble.available);

    d_stream.flush();

    return true;
}
