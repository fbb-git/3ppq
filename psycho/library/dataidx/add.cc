#include "dataidx.ih"

bool DataIdx::add(string const &key, uint64_t dataSize)
{
                            // extend if too many Entries in the .idx file
    if (d_header[N_KEYS] >= s_loadFactor * d_header[SIZE])
        extend();

    Entry entry;
    size_t idx = find(&entry, key);         // find the Entry

    if (entry.key == key)                   // key already in use
        return false;

    fstream out{ d_idxPath, ios::in | ios::out };

    putEntry(out, idx, { key, dataSize });       // write new Entry

    ++d_header[N_KEYS];
    updateHeader(out);

    return true;
}


