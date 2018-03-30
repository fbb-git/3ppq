#include "handler.ih"

void Handler::psychoRequest()
{
    g_log << d_state << ": psychoRequest" << endl;
    for (auto &element: d_cgi)
    {
        g_log << element.first << " = " << endl;
        for (auto &value: element.second)
            g_log << "  `" << value << '\'' << endl;
    }

    Display{"register"};                 // show the psychostart page
}
