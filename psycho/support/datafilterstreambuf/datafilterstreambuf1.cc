#include "datafilterstreambuf.ih"

DataFilterStreambuf::DataFilterStreambuf(istream &in, uint16_t ID)
:
    d_ID(to_string(ID) + ','),
    d_in(in)
{
    if (d_ID.size() < 3 + 1)                        // -> WIPdata.insertRatings
        d_ID.insert(0, 3 + 1 - d_ID.size(), ' ');   // make sure std length
}
