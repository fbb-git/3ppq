#include "display.ih"

void Display::end()
{
    for (string append: d_append)
        cout << append << '\n';

    cout << "\n"
            "</form>\n"
            "<br>\n";

    d_append.clear();
    cout.clear();
}
