#include "tools.ih"

// static
void Tools::delay()
{
    if (size_t seconds = valueOr(g_config.findKeyTail("delay:"), 0))
        this_thread::sleep_for(chrono::seconds(seconds));
}
