#include "handler.ih"

void Handler::logParams()
{
    for (auto const &param: d_cgi)
    {
        g_log << param.first << ':' << endl;
        for (auto const &value: param.second)
            g_log << "  `" << value << '\'' << endl;
    }
}
