#include "wipdata.ih"

bool WIPdata::hasEmail() const
{
    for (string const &address: d_otherEmail)
    {
        if (address.empty())
            return false;
    }

    return true;
}
