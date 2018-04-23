#include "dataidx.ih"

void DataIdx::getEntry(Entry *entry, istream &in, size_t idx)
{
    uint64_t offset = offsetOfEntry(idx);

    in.seekg(offset);

    Tools::readN(in, entry->key, Tools::KEY_SIZE);
    Tools::readN(in, &entry->offset);
}
