#include "dataidx.ih"

void DataIdx::extend()
{
    string wip{ d_idxPath + "-wip" };

    ++d_header[N_BITS];
    initialize(wip);

    ifstream in{ d_idxPath };
    ofstream out{ wip };

                                // process all keys
    for (size_t idx = 0, count = d_header[N_KEYS]; count--; )
    {
        Entry entry;
        getEntry(&entry, in, idx++);

        if (noKey(entry.key))               // empty slot: try the next one
            continue;

        putEntry(out, hash(entry.key), entry);
   }

    updateHeader(out);

    in.close();                                 // close before 
    out.close();                                // renaming

    Tools::rename(wip, d_idxPath);              // new idx file ready
}


