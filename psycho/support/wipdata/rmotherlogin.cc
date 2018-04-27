#include "wipdata.ih"

void WIPdata::rmOtherLogin(size_t idx)
{
    d_otherLogin[idx] = 0;
    d_otherEmail[idx] = '@';
}

