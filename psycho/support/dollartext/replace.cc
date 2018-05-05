#include "dollartext.ih"

// static
void DollarText::replace(string const &outPath, string const &inPath, 
                         StrVector const &elements)
{
    ofstream out;
    Exception::open(out, outPath);

    ifstream in;
    Exception::open(in, inPath);

    string line;
    while (getline(in, line))
        out << replaceLine(line, elements);
}
