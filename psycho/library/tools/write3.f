#include "tools.ih"

inline bool Tools::write(ostream &out, string const &str)
{
    return static_cast<bool>(out.write(&str.front(), str.size()));
}
