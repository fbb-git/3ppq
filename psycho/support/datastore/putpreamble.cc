#include "datastore.ih"

void DataStore::putPreamble(uint64_t offset, 
                                Preamble const &preamble)
{
    d_stream.seekp(offset);

    Tools::writeN(d_stream, preamble.key);
    Tools::writeN(d_stream, &preamble.used);
    Tools::writeN(d_stream, &preamble.available);
}
