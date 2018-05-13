#include "filterstreambuf.ih"

FilterStreambuf::FilterStreambuf(istream &in, uint16_t ID)
:
    d_ID(to_string(ID) + ','),
    d_in(in),
    d_filter(&FilterStreambuf::contentType)
{
    if (d_ID.size() < 3 + 1)                        // -> WIPdata.insertRatings
        d_ID.insert(0, 3 + 1 - d_ID.size(), ' ');   // make sure std length
}
