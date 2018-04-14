#include "display.ih"

void Display::out(string const &path, StrVector const &elements)
{
    state(path);

    cout << DollarText::replaceStream(path, elements);

    end();
}
