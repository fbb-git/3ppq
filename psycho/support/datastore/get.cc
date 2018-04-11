#include "datastore.ih"

bool DataStore::get(string *data, string const &key)
{
    int64_t offset = d_dataIdx.dataOffset(key);
    if (offset == -1)
        return false;                   // no such key

    d_stream.open();

    Preamble preamble = getPreamble(offset);
    data->resize(preamble.used);
    Tools::read(d_stream, &data->front(), preamble.used);

    return true;
}
