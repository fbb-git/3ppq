#include "psych.ih"

string Psych::passParam(char const *name) const
{
    string ret = "<input type='hidden' name='";

    ret += name;
    ret += "' value='";
    ret += d_cgi.param1(name);
    ret += "'>";

    return ret;
}
