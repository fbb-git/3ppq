#include "wipdata.ih"

void WIPdata::remove()
{
    unlink(d_io.path().c_str());
}
