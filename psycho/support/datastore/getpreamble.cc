#include "datastore.ih"

// static
DataStore::Preamble DataStore::getPreamble(istream &in, uint64_t offset)
{
    in.seekg(offset);

    Preamble ret{ {DataIdx::KEY_SIZE, 0} };

    Tools::read(in, &ret.key.front(), DataIdx::KEY_SIZE);
    Tools::read(in, &ret.used);
    Tools::read(in, &ret.available);

    return ret;
}
