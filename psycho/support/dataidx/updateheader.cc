#include "dataidx.ih"

void DataIdx::updateHeader(ostream &out)
{
    out.seekp(0);
    Tools::write(out, d_header, sizeof(d_header));
}
