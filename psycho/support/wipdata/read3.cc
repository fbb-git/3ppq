#include "wipdata.ih"

void WIPdata::read(char const *path)
{
    ifstream in;
    Exception::open(in, path);

    read(in);
}
