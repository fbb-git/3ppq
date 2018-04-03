#include "dataidx.ih"

void DataIdx::getEntry(Entry *entry, istream &in, size_t idx)
{
    uint64_t offset = offsetOfEntry(idx);

    in.seekg(offset);
    entry->key.resize(KEY_SIZE);

    Tools::read(in, &entry->key.front(), KEY_SIZE);
    Tools::read(in, &entry->offset);
}
