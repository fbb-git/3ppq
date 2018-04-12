#include "display.ih"

void Display::append(char const *param, string const &arg)
{
    if (not arg.empty())
        d_append.push_back(
            "<input type='hidden' name='"s + param + "' value='" +  arg + "'>"
        );
}
