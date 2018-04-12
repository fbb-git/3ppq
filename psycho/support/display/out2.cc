#include "display.ih"

void Display::out(string const &path, StrVector const &elements)
{
    cout << DollarText::replaceStream(path, elements);

    end();
}
