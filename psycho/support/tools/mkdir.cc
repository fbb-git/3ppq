#include "tools.ih"

// static
void Tools::mkdir(string const &path)
{
    if (::mkdir(path.c_str(), 0770) != 0)
    {
        g_log << errnodescr << endl;
        throw false;
    }
}
