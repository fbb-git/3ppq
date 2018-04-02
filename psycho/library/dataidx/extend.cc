#include "dataidx.ih"

void DataIdx::extend()
{
    string wip{ d_idxPath + "-wip" };

    ++d_header[N_BITS];
    initialize(wip);

    ifstream in{ d_idxPath };
    ofstream out{ wip };

    in.seekg(sizeof(d_header));             // skip the header

    if (not in)
        throw Exception{} << "Can't find offset " << sizeof(d_header) << '\n';

    while (true)
    {
        Entry entry;
    
        Tools::read(in, &entry, sizeof(Entry));
        if (not in)
            break;

        if (entry.key == 0)                 // empty slot: try the next one
            continue;

        size_t idx = hash(entry.key);                       // new location
        out.seekp(sizeof(d_header) + idx * sizeof(Entry));  // dest. loc.

        Tools::write(out, &entry, sizeof(Entry));      // write the Entry
    }

    updateHeader(out);

    in.close();                                         // close before 
    out.close();                                        // renaming

    rename(wip.c_str(), d_idxPath.c_str());             // new idx file ready
}


