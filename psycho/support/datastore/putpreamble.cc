#include "datastore.ih"

// static
void DataStore::putPreamble(ostream &out, uint64_t offset, 
                            Preamble const &preamble)
{
    out.seekp(offset);

    Tools::write(out, &preamble.key.front(), DataIdx::KEY_SIZE);
    Tools::write(out, &preamble.used);
    Tools::write(out, &preamble.available);
}
