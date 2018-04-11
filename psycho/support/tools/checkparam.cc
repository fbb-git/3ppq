#include "tools.ih"

//static
bool Tools::checkParam(CGI &cgi, char const *param)
{
    string value = cgi.param1(param);

    for (int ch: value)
    {
        if (not isprint(ch))
            return false;
    }

    return not value.empty();
}
