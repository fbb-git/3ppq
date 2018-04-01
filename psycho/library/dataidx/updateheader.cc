#include "dataidx.ih"

void DataIdx::updateHeader()
{
    d_idx.seekp(0);
    Tools::write(d_idx, d_header, sizeof(d_header));
}
