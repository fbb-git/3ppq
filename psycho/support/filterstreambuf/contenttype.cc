#include "filterstreambuf.ih"

bool FilterStreambuf::contentType(
                            char const **srcBegin, char const **srcEnd) 
{
    while (getline(d_in, d_buffer))
    {
        if (d_buffer.find(d_ID) == 0)
        {
            d_buffer += "\n\n";

            cout << "Content-type: text/csv\r\n\r\n";
            d_filter = &FilterStreambuf::trailer;

            *srcBegin = &d_buffer.front();
            *srcEnd   = &d_buffer.back();

            return true;
        }
    }

    return false;
}
