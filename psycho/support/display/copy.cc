#include "display.ih"

void Display::copy()
{
    if (d_dollarVars != 0)
        cout << DollarText{ d_path, *d_dollarVars }.text();
    else
    {
        ifstream in;
        Exception::open(in, d_path);
        cout << in.rdbuf();                 // no variables: file to cout
    }

}
