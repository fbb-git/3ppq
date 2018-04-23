#include "dataidx.ih"

void DataIdx::putEntry(ostream &out, size_t idx, Entry const &entry) const
{
    out.seekp(offsetOfEntry(idx));

    Tools::writeN(out, entry.key);
    Tools::writeN(out, &entry.offset);    
}
