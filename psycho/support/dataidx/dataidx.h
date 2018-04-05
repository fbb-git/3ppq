#ifndef INCLUDED_DATAIDX_
#define INCLUDED_DATAIDX_

#include <iosfwd>
#include <fstream>

class DataIdx
{
    enum Header                 // indices in d_header
    {
        N_KEYS,                 // keys in use
        N_BITS,                 // # bits used for the prime computations
        SIZE,                   // locations available
        sizeHeader
    };

    static constexpr uint16_t   s_primeBits = 6;        // inital # prime bits
    static constexpr double     s_loadFactor = 0.6;

    struct Entry
    {
        std::string key;        // KEY_SIZE bytes
        uint64_t offset;
    };

    std::string d_idxPath;

    uint16_t d_header[sizeHeader];

    public:
        enum 
        {
            KEY_SIZE = 16               // size of MD5 hash
        };

        DataIdx(std::string dataIdxPath);

        int64_t dataOffset(std::string const &key); // -1 if not found
                                                    // otherwise offset in
                                                    // dataIdx of key's record

                                                // false: already available
        bool add(std::string const & key, uint64_t dataSize);  

        int64_t erase(std::string const &key);  // -1: not found, 
                                                // else Data offset

        void reduceOffsets(uint64_t offset, uint64_t delta);

    private:
        void extend();                  // extend the .idx file
        void updateHeader(std::ostream &out);

        void initialize(std::string const &path);
        size_t hash(std::string const &key) const;

            // find the Entry matching 'key': fill entry, return the Entry's 
            // index in the .idx file
        size_t find(Entry *entry, std::string const &key);

                                        // return offset of the entry
        void getEntry(Entry *entry, std::istream &in, size_t idx);
        void putEntry(std::ostream &out, size_t idx, Entry const &entry) 
                                                                        const;
        uint64_t offsetOfEntry(size_t idx) const;

        static bool noKey(std::string const &key);
};
        
#endif
