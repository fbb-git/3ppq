#include "dollartext.ih"

string DollarText::replace(StrVector &dest, string const &path)
{
    string ret = replacePath(path);

    dest = move(d_dollarText);
    d_dollarText = StrVector{};

    return ret;
}
