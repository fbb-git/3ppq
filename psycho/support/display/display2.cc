#include "display.ih"

Display::Display(StrVector const &append,
                 string const &path, StrVector const *dollarVars)
:
    d_path(path),
    d_dollarVars(dollarVars),
    d_append(&append)
{
    copy();
}
