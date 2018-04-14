#include "display.ih"

void Display::out(string const &path)
{
    state(path);

    ifstream in;
    Exception::open(in, path);

    cout << in.rdbuf();                 // no variables: file to cout

    end();
}
