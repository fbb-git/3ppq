#include "datastore.ih"

void DataStore::reduce(int64_t from, int64_t to)
{
    char *buffer = new char[1000];

    d_stream.open();

    while (true)
    {
        d_stream.seekg(from);
        size_t size = d_stream.read(buffer, 1000).gcount(); // read a block
        if (size == 0)
            break;

        d_stream.clear();
        d_stream.seekp(to);

        d_stream.write(buffer, size);                       // write the block

        to += size;                                         // next block
        from += size;
    }

    d_stream.close();
    truncate(d_path.c_str(), to);
}
