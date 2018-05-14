#include "handler.ih"

void Handler::logParams()
{
    g_log << "error-exception. received parameters:" << endl;

    for (auto const &param: d_cgi)
    {
        g_log << param.first << ": ";
        for (auto const &value: param.second)
            g_log << "  `" << value << "', ";
        g_log << endl;
    }
}
