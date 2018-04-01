#include "dataidx.ih"

DataIdx::DataIdx(string basepath)
:
    d_idxPath(basepath + ".idx"),
    d_idx(d_idxPath)
{
    if (Tools::size(d_idx) == 0)
    {
        d_header[N_KEYS] = 0;                       // initialize the header
        d_header[N_BITS] = s_primeBits;
        initialize(d_idxPath);
    }

    d_idx.close();
}
