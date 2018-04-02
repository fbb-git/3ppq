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
        size_t key;
        uint64_t offset;
    };

    std::string d_idxPath;

    uint16_t d_header[sizeHeader];

    public:
        DataIdx(std::string basepath);

        int64_t dataOffset(size_t key);             // -1 if not found
                                                    // otherwise offset in
                                                    // dataIdx of key's record

        bool add(size_t key, uint64_t dataSize);  // false: already available
        int64_t erase(size_t key);         // -1: not found, else Data offset

        void reduceOffsets(uint64_t offset, uint64_t delta);

    private:
        void extend();                  // extend the .idx file
        void updateHeader(std::ostream &out);

        void initialize(std::string const &path);
        size_t hash(size_t key) const;

            // find the Entry matching 'key': fill entry, return offset in 
            // the .idx file
        uint64_t find(Entry *entry, size_t key);
};
        
#endif
