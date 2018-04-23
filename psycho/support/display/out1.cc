#include "display.ih"

void Display::out(string const &name)
{
    string path = g_options.html() + name;

    state(path);

    ifstream in;
    Exception::open(in, path);

    cout << in.rdbuf();                 // no variables: file to cout

    end();
}
