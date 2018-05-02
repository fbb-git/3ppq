#include "wipdata.ih"

void WIPdata::write() const
{
    d_io.seekp(0);
    write(d_io);
}
