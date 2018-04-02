#include "dataidx.ih"

int64_t DataIdx::erase(size_t key)
{
    Entry entry;
    uint64_t offset = find(&entry, key);

    if (entry.key != key)
        return -1;                      // no such key

    fstream out{ d_idxPath, ios::in | ios::out };
    out.seekp(offset);                  // go to the Entry's offset
    offset = entry.offset;              // save the data-offset to return

    entry = Entry{ 0, 0 };              // clear the entry
    Tools::write(out, &entry, sizeof(Entry));

    --d_header[N_KEYS];                 // entry removed
    updateHeader(out);

    return offset;                // return offset in the data file
}
