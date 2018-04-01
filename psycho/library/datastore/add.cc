#include "datastore.ih"

bool DataStore::add(uint64_t key, uint64_t iv, string const &data)
{
    LockGuard lck{d_data};

    d_data.seekp(0, ios::end);

    if (not d_dataIdx.add(key, d_data.tellp()))
        return false;
    
    Tools::write(d_data, &key);
    Tools::write(d_data, &iv);
    d_data.write(&data.front(), data.size());

    d_data.flush();

    return true;
}
