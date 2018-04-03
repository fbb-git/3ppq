#include "dataidx.ih"

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
