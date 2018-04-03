#include "dataidx.ih"

// static
bool DataIdx::noKey(string const &key)
{
    for (char ch: key)
    {
        if (ch != 0)                // not an empty key field if at least
            return false;           // one byte has a non-0 value
    }
    return true;                    // empty key if all bytes are 0
}
