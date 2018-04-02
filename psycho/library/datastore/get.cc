#include "datastore.ih"

bool DataStore::get(string *data, uint64_t key)
{
    int64_t offset = d_dataIdx.dataOffset(key);
    if (offset == -1)
        return false;                   // no such key

    fstream in{ open() };

    in.seekg(offset);
    Preamble preamble;
    Tools::read(in, &preamble);

    data->resize(preamble.used);
    Tools::read(in, &data->front(), preamble.used);
    return true;
}
