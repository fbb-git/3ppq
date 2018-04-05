#include "dataidx.ih"

void DataIdx::reduceOffsets(uint64_t offset, uint64_t delta)
{
    fstream io;
    Exception::open(io, d_idxPath, ios::in | ios::out);

    io.seekg(sizeof(d_header));              // skip the header

    for (size_t idx = -1, count = d_header[N_KEYS]; count--; )
    {
        Entry entry;
        while (true)
        {
            getEntry(&entry, io, ++idx);

            if (noKey(entry.key))
                continue;                   // empty entry: get the next one

                // inspect an actual Entry:

            if (entry.offset > offset)      // reduce entry offsets > offset
            {
                entry.offset -= delta;
                                            
                putEntry(io, idx, entry);
            }
            
            break;                          // find the next one, if
        }                                   // available
    }
}
