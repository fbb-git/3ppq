#include "display.ih"

// static
void Display::state(string const &path)
{
    Tools::debug() << "state: " << path.substr(path.rfind('/') + 1) << endl;
}
