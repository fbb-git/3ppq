#include "datastore.ih"

DataStore::Preamble DataStore::getPreamble(uint64_t offset)
{
    d_stream.seekg(offset);

    Preamble ret;

    Tools::readN(d_stream, ret.key, Tools::KEY_SIZE);
    Tools::readN(d_stream, &ret.used);
    Tools::readN(d_stream, &ret.available);

    return ret;
}
