#include "wipdata.ih"

bool WIPdata::hasEmail() const
{
    for (string const &address: d_otherMail)
    {
        if (address.empty())
            return false;
    }

    return true;
}
