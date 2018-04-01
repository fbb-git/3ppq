#include "dataidx.ih"

size_t DataIdx::hash(size_t key) const
{
    size_t ret = key % d_header[SIZE];

    if (ret == 0)
    {
        ret = key / d_header[SIZE] % d_header[SIZE];
        if (ret == 0)
            ret = 1;
    }

    return ret;
}
