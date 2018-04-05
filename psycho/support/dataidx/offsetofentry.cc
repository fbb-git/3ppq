#include "dataidx.ih"

uint64_t DataIdx::offsetOfEntry(size_t idx) const
{
    return sizeof(d_header) + idx * (KEY_SIZE + sizeof(uint64_t));
}
