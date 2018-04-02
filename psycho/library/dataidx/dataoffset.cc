#include "dataidx.ih"

    // return offset in data file where key is found
int64_t DataIdx::dataOffset(size_t key)
{
    Entry entry;
    find(&entry, key);          // find the Entry matching key (may be empty) 

    if (entry.key != key)       // not found
        return -1;
    
    return entry.offset;        // return offset in the data, d_idx is locked
}
