#include "tools.ih"

inline bool Tools::writeN(ostream &out, string const &str)
{
    return static_cast<bool>(out.write(&str.front(), str.size()));
}
