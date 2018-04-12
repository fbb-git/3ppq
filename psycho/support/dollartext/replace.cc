#include "dollartext.ih"

string DollarText::replace(string const &path)
{
    string ret = replacePath(path);
    clear();

    return ret;
}
