#ifndef INCLUDED_DATASTORE_
#define INCLUDED_DATASTORE_

#include <string>
#include <fstream>

#include "../dataidx/dataidx.h"

class DataStore
{
    struct Preamble
    {
        uint64_t key;           // used for back-retrieval
        size_t   used;          // actual size of the stored data
        size_t   available;     // size of the available data space
    };

    std::string d_path;
    DataIdx d_dataIdx;

    public:
        DataStore(std::string const &path);     // full path to the data file

                                        // add to the end of d_data (true: OK)
        bool add(uint64_t key, std::string const &data);
        bool get(std::string *data, uint64_t key);
        bool erase(uint64_t key);               // erase data and key
        bool update(uint64_t key, std::string const &data);

    private:
        void reduce(int64_t from, int64_t to);
        std::fstream open();
};

#endif

