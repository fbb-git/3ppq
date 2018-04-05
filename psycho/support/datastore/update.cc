#include "datastore.ih"

bool DataStore::update(string const &key, string const &data)
{
    int64_t offset = d_dataIdx.dataOffset(key);
    if (offset == -1)
        return false;                   // no such key

    fstream io{ open() };

    Preamble preamble{ getPreamble(io, offset) };

    if (data.size() <= preamble.used)       // new does not exceed current
    {
        preamble.used = data.size();        // update preamble and overwrite 
        putPreamble(io, offset, preamble);  
                                            // write the data
        Tools::write(io, &data.front(), preamble.used);
        return true;
    }

    erase(key);                         // new exceeds current: remove old
    add(key, data);                     // add new.

    return true;
}
