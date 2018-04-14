#include "tools.ih"

void Tools::setLogLevel()
{
    string log = g_config.findKeyTail("log:");

    if (log.empty() || log == "off")
        g_log.off();
    else if (log == "debug")
        g_log.setLevel(0);
}
