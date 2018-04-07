#include "tools.ih"

// static
string Tools::passParam(CGI &cgi, char const *name)
{
    string ret = "<input type='hidden' name='";

    ret += name;
    ret += "' value='";
    ret += cgi.param1(name);
    ret += "'>";

    return ret;
}
