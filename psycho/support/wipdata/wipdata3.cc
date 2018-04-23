#include "wipdata.ih"

WIPdata::WIPdata(string const &pid, string const &cid)
:
    WIPdata(pid + '.' + cid + '=')
{}
