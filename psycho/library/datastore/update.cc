#include "datastore.ih"

bool DataStore::update(uint64_t key, string const &data)
{
    int64_t offset = d_dataIdx.dataOffset(key);
    if (offset == -1)
        return false;                   // no such key

    fstream in{ open() };

    in.seekg(offset);
    Preamble preamble;
    Tools::read(in, &preamble);

    if (data.size() <= preamble.used)       // new does not exceed current
    {
        preamble.used = data.size();        // update used and overwrite 
        in.seekp(-sizeof(Preamble), ios::cur);    // current
        Tools::write(in, &preamble);
        Tools::write(in, &data.front(), preamble.used);
        return true;
    }

    erase(key);                         // new exceeds current: remove old
    add(key, data);                     // add new.

    return true;
}
