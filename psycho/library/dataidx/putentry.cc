#include "dataidx.ih"

void DataIdx::putEntry(ostream &out, size_t idx, Entry const &entry) const
{
    out.seekp(offsetOfEntry(idx));

    Tools::write(out, &entry.key.front(), KEY_SIZE);
    Tools::write(out, &entry.offset);    
}
