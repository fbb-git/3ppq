#include "wipdata.ih"

// static
void WIPdata::remove(uint16_t pid, string const &cid)
{
    string wipPath = path(pid, cid);

    unlink(wipPath.c_str());
    unlink((wipPath + ".lck").c_str());
}
