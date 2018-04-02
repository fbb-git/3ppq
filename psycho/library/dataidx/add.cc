#include "dataidx.ih"

bool DataIdx::add(size_t key, uint64_t dataSize)
{
                            // extend if too many Entries in the .idx file
    if (d_header[N_KEYS] >= s_loadFactor * d_header[SIZE])
        extend();

    Entry entry;
    uint64_t offset = find(&entry, key);    // find the Entry

    if (entry.key == key)                   // key already in use
        return false;

    fstream out{ d_idxPath, ios::in | ios::out };
    out.seekp(offset);                      // entry's offset
    entry = {key, dataSize};                // define new Entry
    Tools::write(out, &entry, sizeof(Entry));

    ++d_header[N_KEYS];
    updateHeader(out);

    return true;
}


