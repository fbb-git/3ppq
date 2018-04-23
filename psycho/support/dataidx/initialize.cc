#include "dataidx.ih"

void DataIdx::initialize(std::string const &path)
{
    d_header[SIZE] = BigInt::prime(d_header[N_BITS]).ulong();

    ofstream out;
    Exception::open(out, path);

    Tools::writeB(out, d_header, sizeof(d_header));    // write the header

    out.seekp(d_header[SIZE] * sizeof(Entry) - 1, ios::cur);
    out.put(0);
}
