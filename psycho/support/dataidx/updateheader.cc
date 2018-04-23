#include "dataidx.ih"

void DataIdx::updateHeader(ostream &out)
{
    out.seekp(0);
    Tools::writeB(out, d_header, sizeof(d_header));
}
