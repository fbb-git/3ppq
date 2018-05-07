#include "dataidx.ih"

DataIdx::Entry *DataIdx::nextEntry(size_t *idxOffset) const
{
    ifstream in;
    Exception::open(in, d_idxPath);

    static Entry entry;
    static size_t nEntries;
    static size_t entryIdx;

    uint16_t header[sizeHeader];

    if (*idxOffset != 0)
        in.seekg(*idxOffset);
    else
    {
        Tools::readB(in, header, sizeof(header));
        nEntries = header[N_KEYS]; 
        entryIdx = 0;
    }

    if (entryIdx == nEntries)           // all entries processed
        return 0;

    while (true)
    {
        if (Tools::readN(in, entry.key, Tools::KEY_SIZE) == 0)
            throw Exception{} << "EOF of " << d_idxPath << 
                                 " reached after reading " << entryIdx << 
                                 " out of " << nEntries << " Entries";

        Tools::readN(in, &entry.offset);    // read the file offset

        if (entry.offset != 0)              // got an entry
        {
            *idxOffset = in.tellg();
            ++entryIdx;

            return &entry;
        }
    }
}
