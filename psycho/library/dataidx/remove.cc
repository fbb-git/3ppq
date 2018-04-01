#include "dataidx.ih"

int64_t DataIdx::remove(size_t key)
{
    Entry entry;
    uint64_t offset = find(&entry, key);

    if (entry.key != key)
        return -1;                      // no such key

    d_idx.seekp(offset);                // go to the Entry's offset
    offset = entry.offset;              // save the data-offset to return

    entry = Entry{ 0, 0 };              // clear the entry
    Tools::write(d_idx, &entry, sizeof(Entry));
    d_idx.flush();

    return offset;                      // return offset in the data file
}
