#include "datastore.ih"

DataStore::Preamble DataStore::getPreamble(uint64_t offset)
{
    d_stream.seekg(offset);

    Preamble ret{ {Tools::KEY_SIZE, 0} };

    Tools::read(d_stream, &ret.key.front(), Tools::KEY_SIZE);
    Tools::read(d_stream, &ret.used);
    Tools::read(d_stream, &ret.available);

    return ret;
}
