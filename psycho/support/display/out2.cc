#include "display.ih"

void Display::out(string const &name, StrVector const &elements)
{
    string path = g_options.html() + name;

    state(path);

    cout << DollarText::replaceStream(path, elements);

    end();
}
