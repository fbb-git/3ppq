#include "dataidx.ih"

uint64_t DataIdx::find(Entry *entry, size_t key)
{
    size_t idx = hash(key);                         // key's hash value
    size_t firstIdx = idx;

    while (true)
    {                                               // try this location
        uint64_t offset = sizeof(d_header) + idx * sizeof(Entry);
        d_idx.seekg(offset);
        Tools::read(d_idx, entry);                  // read the Entry

        if (entry->key == 0 || entry->key == key)   // if empty or hit: 
            return offset;                          // done
        
        idx = (idx + firstIdx) % d_header[SIZE];    // add the hash-rehash
    }
}
