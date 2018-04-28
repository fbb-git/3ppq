#include "datastore.ih"

bool DataStore::get(string *data, uint64_t offset)
{
    Preamble preamble = getPreamble(offset);

    cerr << "preamble used: " << preamble.used << ", available = " <<
            preamble.available << '\n';

    return Tools::readN(d_stream, *data, preamble.used);
}
