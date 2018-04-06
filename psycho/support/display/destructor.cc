#include "display.ih"

Display::~Display()
{
    if (d_append)
    {
        for (string const &line: *d_append)
        {
            g_log << "adding parameter `" << line << '\'' << endl;
            cout << line << '\n';
        }
    }

    cout << "\n"
            "</form>\n"
            "<hr>\n";

    cout.clear();
}
