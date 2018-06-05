#include "dataidx.ih"

    // return the Entry's index in the DataIdx table

size_t DataIdx::find(Entry *entry, string const &key)
{
    size_t idx = hash(key);                         // key's hash value
    size_t firstIdx = idx;

    ifstream in{ d_idxPath };

    while (true)
    {                                               // try this location
        getEntry(entry, in, idx);

        if (noKey(entry->key) || entry->key == key) // if empty or hit: 
            return idx;                             // return key's location
        
        idx = (idx + firstIdx) % d_header[SIZE];    // add the hash-rehash
    }
}
