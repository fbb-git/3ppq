#include "tools.ih"

// static
string Tools::passParam(char const *name, string const &value)
{
    string ret = "<input type='hidden' name='";

    ret += name;
    ret += "' value='";
    ret += value;
    ret += "'>";

    return ret;
}
