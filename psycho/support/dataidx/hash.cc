#include "dataidx.ih"

    // the lower 8 bytes of the hash value of the key (hashed e-mail address)
    // is used  as initial index of the entry in the dataStore. 

    // The modulo d_header[SIZE] value is then used as the actual
    // index. Because an add-the-hash procedure is used, the index may not be
    // 0.

    // If it's zero then the modulo value of the 'div d_header[SIZE]' value
    // is used. If that one's 0 then 1 is used.

    // The returned value is the index in the DataIdx table corresponding to
    // the (hash value of the) used e-mail address

size_t DataIdx::hash(std::string const &key) const
{
    uint64_t lower8 = *reinterpret_cast<uint64_t const *>(&key.front());
    size_t ret = lower8 % d_header[SIZE];

    if (ret == 0)
    {
        ret = lower8 / d_header[SIZE] % d_header[SIZE];
        if (ret == 0)
            ret = 1;
    }

    return ret;
}
