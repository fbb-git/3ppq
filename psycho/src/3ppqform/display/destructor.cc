#include "display.ih"

Display::~Display()
{
    if (not d_line.empty())
        cout << d_line << '\n';

    cout << d_file.rdbuf() << "<hr>";

    cout.clear();
}
