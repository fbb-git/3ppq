#include "dataidx.ih"

void DataIdx::reduceOffsets(uint64_t offset, uint64_t delta)
{
    fstream idx;
    Exception::open(idx, d_idxPath, ios::in | ios::out);

    idx.seekg(sizeof(d_header));              // skip the header

    for (size_t count = d_header[N_KEYS]; count--; )
    {
        Entry entry;
        while (true)
        {
            Tools::read(idx, &entry);
            if (entry.key != 0)
            {
                if (entry.offset > offset)      // reduce offsets > offset
                {
                    entry.offset -= delta;
                                                // rewrite the Entry
                    idx.seekp(-sizeof(Entry), ios::cur);
                    Tools::write(idx, &entry);
                    idx.seekg(idx.tellp());
                }
                break;                          // find the next one, if
            }                                   // available
        }
    }
}
