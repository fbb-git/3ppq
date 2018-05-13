#include "datafilterstreambuf.ih"

bool DataFilterStreambuf::filter(char const **srcBegin, char const **srcEnd) 
{
    while (getline(d_in, d_buffer))
    {
        if (d_buffer.find(d_ID) == 0)
        {
            d_buffer += "\n\n";

            if (not d_csvData)
            {
                d_csvData = true;
                cout << "Content-type: text/csv\r\n\r\n";
            }

            *srcBegin = &d_buffer.front();
            *srcEnd   = &d_buffer.back();


            return true;
        }
    }

    return false;
}
