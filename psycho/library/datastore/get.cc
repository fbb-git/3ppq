#include "datastore.ih"

bool DataStore::get(string *data, string const &key)
{
    int64_t offset = d_dataIdx.dataOffset(key);
    if (offset == -1)
        return false;                   // no such key

    fstream in{ open() };

    Preamble preamble = getPreamble(in, offset);

    data->resize(preamble.used);
    Tools::read(in, &data->front(), preamble.used);

    return true;
}
