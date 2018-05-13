#include "filterstreambuf.ih"

bool FilterStreambuf::filter(char const **srcBegin, char const **srcEnd) 
{
    return (this->*d_filter)(srcBegin, srcEnd);
}
