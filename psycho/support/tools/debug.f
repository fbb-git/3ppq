#include "tools.ih"

inline std::ostream &Tools::debug()
{
    return g_log << FBB::level(LOG_DEBUG);
}
