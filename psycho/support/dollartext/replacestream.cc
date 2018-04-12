#include "dollartext.ih"

string DollarText::replaceStream(string const &path, 
                                 StrVector const &elements)
{
    ifstream in;
    Exception::open(in, path);

    string ret;
    string line;

    while (getline(in, line))
        ret += replaceLine(line, elements);

    return ret;
}
