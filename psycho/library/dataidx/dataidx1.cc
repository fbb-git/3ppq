#include "dataidx.ih"

DataIdx::DataIdx(string path)
:
    d_idxPath(path)
{
    if (Tools::exists(d_idxPath))
    {
        ifstream in{ d_idxPath };
        Tools::read(in, d_header, sizeof(d_header));
    }
    else
    {
        d_header[N_KEYS] = 0;                       // initialize the header
        d_header[N_BITS] = s_primeBits;

        initialize(d_idxPath);
    }
}
