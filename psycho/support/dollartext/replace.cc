#include "dollartext.ih"

// static
void DollarText::replace(ostream &out, string const &inPath, 
                         StrVector const &elements)
{
    ifstream in;
    Exception::open(in, inPath);

    string line;
    while (getline(in, line))
        out << replaceLine(line, elements);

    out.flush();
}
