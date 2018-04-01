#include "dataidx.ih"

    // file already locked.
void DataIdx::extend()
{
    string wip{ d_idxPath + "-wip" };

    ++d_header[N_BITS];
    initialize(wip);

    ifstream in(d_idxPath);
    in.seekg(sizeof(d_header));             // skip the header

    d_header[N_KEYS] = 0;                   // fill the new idx file
    while (true)
    {
        Entry entry;
    
        Tools::read(in, &entry, sizeof(Entry));
        if (entry.key == 0)                 // empty slot: try the next one
            continue;
        
        size_t idx = hash(entry.key);                       // new location
        d_idx.seekp(sizeof(d_header) + idx * sizeof(Entry));    // dest. loc.

        Tools::write(d_idx, &entry, sizeof(Entry));      // write the Entry
    }

    updateHeader();

    in.close();                                         // close before 
    d_idx.close();                                      // renaming

    rename(wip.c_str(), d_idxPath.c_str());             // new idx file ready
}
