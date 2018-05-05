#include "display.ih"

void Display::out(string const &name)
{
    string path = g_options.htmlDir() + name;

    state(path);

    ifstream in;
    Exception::open(in, path);

    cout << in.rdbuf();                 // no variables: file to cout

    end();
}
