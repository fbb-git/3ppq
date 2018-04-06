#include "dollartext.ih"

string DollarText::text() const
{
    ifstream in;

    Exception::open(in, d_path);

    string ret;
    string line;

    while (getline(in, line))
        ret += replaceDollars(line);

    return ret;
}
