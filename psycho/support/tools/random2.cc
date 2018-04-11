#include "tools.ih"

// static
size_t Tools::random(int first, int last)           // return [first .. last]
{
    return first + random(last - first + 1);
}

