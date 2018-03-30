#include "display.ih"

Display::Display(string const &name)
:
    d_file(s_base + name)
{
    copy();                 // write the head of the page to cout
}
