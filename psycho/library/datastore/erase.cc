#include "datastore.ih"

bool DataStore::erase(uint64_t key)
{
    int64_t offset = d_dataIdx.erase(key);

    if (offset == -1)
        return false;

    fstream in{ open() };               // cpt the size of the record to erase
    in.seekg(offset);
    Preamble preamble;
    Tools::read(in, &preamble);         // first find the data size

                                        // then determine the next offset
    int64_t nextOffset = offset + sizeof(Preamble) + preamble.available;

    d_dataIdx.reduceOffsets(offset, nextOffset - offset);   

    reduce(nextOffset, offset);         // reduce the data fm nextOffset to
                                        // offset
    return true;
}
