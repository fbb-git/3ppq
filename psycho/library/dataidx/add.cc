#include "dataidx.ih"

bool DataIdx::add(size_t key, uint64_t dataSize)
{
                            // extend if too many Entries in the .idx file
    if (d_header[N_KEYS] >= s_loadFactor * d_header[N_KEYS])
        extend();

    Entry entry;
    find(&entry, key);                  // find the Entry

    if (entry.key == key)               // key already in use
        return false;

    d_idx.seekp(ios::end);              // end of idx file
    entry.offset = dataSize;

    Tools::write(d_idx, &entry, sizeof(Entry));

    ++d_header[N_KEYS];
    updateHeader();

    return true;
}


