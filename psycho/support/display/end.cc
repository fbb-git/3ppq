#include "display.ih"

void Display::end()
{
    for (string append: d_append)
        cout << append << '\n';

    d_append.clear();
    cout.clear();
}
