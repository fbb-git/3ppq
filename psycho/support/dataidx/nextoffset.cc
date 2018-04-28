#include "dataidx.ih"

//static
uint64_t DataIdx::nextOffset(istream &in)
{
    Entry entry;

    while (true)
    {
        if (Tools::readN(in, entry.key, Tools::KEY_SIZE) == 0)
            return ~0ULL;

        Tools::readN(in, &entry.offset);


        for (int ch: entry.key)
        {
            if (ch != 0)
                return entry.offset;
        }
    }
}
