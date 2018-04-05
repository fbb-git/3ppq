#ifndef INCLUDED_DATASTORE_
#define INCLUDED_DATASTORE_

#include <string>
#include <fstream>

#include "../dataidx/dataidx.h"

// keys must be DataIdx::KEY_SIZE bytes. NOT checked!

class DataStore
{
    struct Preamble
    {
        std::string key;            // 16 byte MD5 hash
        size_t      used;           // actual size of the stored data
        size_t      available;      // size of the available data space
    };

    std::string d_path;
    DataIdx d_dataIdx;
    
    public:
        DataStore(std::string const &path);     // full path to the data file

        bool find(std::string const &key);

                                        // add to the end of d_data (true: OK)
        bool add(std::string const &key, std::string const &data);
        bool get(std::string *data, std::string const &key);
        bool erase(std::string const &key);     // erase data and key
        bool update(std::string const &key, std::string const &data);

    private:
        void reduce(int64_t from, int64_t to);
        std::fstream open();

        static Preamble getPreamble(std::istream &in, uint64_t offset);
        static void putPreamble(std::ostream &out, uint64_t offset, 
                                Preamble const &preamble);
};

inline bool DataStore::find(std::string const &key)
{
    return d_dataIdx.dataOffset(key) != -1;     // -1: not found
}



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

