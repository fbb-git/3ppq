#include "display.ih"

void Display::end()
{
    cout << "\n"
            "</form>\n"
            "<hr>\n";

    d_append.clear();
    cout.clear();
}
