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

// A common setup of data storage/updates and retrieval works like this:
//
//  Storage:
//  1. determine a key
//  2. obtain information: part I: not encrypted, part II: encrypted
//  3. encrypt part II: write to a string
//  4. determine the size of the unencrypted data (this may conveniently be
//      stored in the unencrypted data, or it may be written as the first
//      value in the stored data
//  4. append the encrypted bytes to the string holding the unencrypted bytes
//      (+ their size). 
//  5. store (or update) the data for the specified key.
//
//  Retrieval:
//  1. determine the key.
//  2. retrieve the key's data
//  4. determine the location of the encrypted data
//  5. decrypt the encrypted data
//  6. convert the unencrypted bytes to, e.g., the unencrypted data struct
//  7. convert the decrypted bytes to, e.g., the confidential data struct
    
#endif

