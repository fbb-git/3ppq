#include "lfstream.ih"

Lfstream::Lfstream(string const &path)
{
    open(path);
}
