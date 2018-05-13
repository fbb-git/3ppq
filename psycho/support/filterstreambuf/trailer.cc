#include "filterstreambuf.ih"

bool FilterStreambuf::trailer(
                            char const **srcBegin, char const **srcEnd) 
{
    while (getline(d_in, d_buffer))
    {
        if (d_buffer.find(d_ID) == 0)
        {
            d_buffer += "\n\n";

            *srcBegin = &d_buffer.front();
            *srcEnd   = &d_buffer.back();

            return true;
        }
    }

    return false;
}
