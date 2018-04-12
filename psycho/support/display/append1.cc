#include "display.ih"

void Display::append(std::initializer_list<char const *> params)
{
    for (char const *param: params)
        append(param, d_cgi->param1(param));
}

