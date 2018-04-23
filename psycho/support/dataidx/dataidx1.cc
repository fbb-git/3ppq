#include "dataidx.ih"

DataIdx::DataIdx(string dataIdxPath)
:
    d_idxPath(dataIdxPath)
{
    if (Tools::exists(d_idxPath))
    {
        ifstream in;
        Exception::open(in, d_idxPath);
        Tools::readB(in, d_header, sizeof(d_header));
    }
    else
    {
        d_header[N_KEYS] = 0;                       // initialize the header
        d_header[N_BITS] = s_primeBits;

        initialize(d_idxPath);
    }
}
