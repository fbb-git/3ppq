#include "datastore.ih"

void DataStore::putPreamble(uint64_t offset, 
                                Preamble const &preamble)
{
    d_stream.seekp(offset);

    Tools::write(d_stream, &preamble.key.front(), Tools::KEY_SIZE);
    Tools::write(d_stream, &preamble.used);
    Tools::write(d_stream, &preamble.available);
}
