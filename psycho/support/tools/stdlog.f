#include "tools.ih"

inline std::ostream &Tools::stdLog()
{
    return g_log << FBB::level(LOG_STD);
}
