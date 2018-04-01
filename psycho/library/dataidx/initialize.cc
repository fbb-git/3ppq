#include "dataidx.ih"

void DataIdx::initialize(std::string const &path)
{
    d_header[SIZE] = BigInt::prime(d_header[N_BITS]).ulong();

    Tools::write(d_idx, d_header, sizeof(d_header));    // write the header
    d_idx.seekp(d_header[SIZE] * sizeof(Entry) - 1, ios::cur);
    d_idx.put(0);
}
