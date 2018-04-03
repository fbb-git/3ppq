#include "dataidx.ih"

int64_t DataIdx::erase(string const &key)
{
    Entry entry;

    size_t idx = find(&entry, key);
    if (entry.key != key)
        return -1;                      // no such key

    fstream out{ d_idxPath, ios::in | ios::out };

    putEntry(out, idx, { string(KEY_SIZE, 0), 0 });

    --d_header[N_KEYS];                 // entry removed
    updateHeader(out);

    return entry.offset;                // return offset in the data file
}
