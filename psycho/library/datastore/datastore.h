#ifndef INCLUDED_DATASTORE_
#define INCLUDED_DATASTORE_

#include <string>

#include "../lfstream/lfstream.h"
#include "../dataidx/dataidx.h"

class DataStore
{
    std::string d_path;

    DataIdx d_dataIdx;
    Lfstream d_data;

    public:
        DataStore(std::string const &path);

                                        // add to the end of d_data (true: OK)
        bool add(uint64_t key, uint64_t iv, std::string const &data);
    private:
};
        
#endif
