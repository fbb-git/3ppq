#include "datastore.ih"

void DataStore::reduce(int64_t from, int64_t to)
{
    char *buffer = new char[1000];

    fstream data;
    Exception::open(data, d_path, ios::in | ios::out);

    while (true)
    {
        data.seekg(from);
        size_t size = data.read(buffer, 1000).gcount();     // read a block
        if (size == 0)
            break;

        data.clear();
        data.seekp(to);

        data.write(buffer, size);                           // write the block

        to += size;                                         // next block
        from += size;
    }
    data.close();
    truncate(d_path.c_str(), to);
}
