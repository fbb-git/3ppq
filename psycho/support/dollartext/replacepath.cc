#include "dollartext.ih"

string DollarText::replacePath(string const &path)
{
    ifstream in;
    Exception::open(in, path);

    string ret;
    string line;

    while (getline(in, line))
        ret += replaceDollars(line);

    return ret;
}
