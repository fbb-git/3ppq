#include "display.ih"

Display::Display(string const &path, StrVector const *dollarVars)
:
    d_path(path),
    d_dollarVars(dollarVars)
{
    copy();
}
