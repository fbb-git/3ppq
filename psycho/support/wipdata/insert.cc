#include "wipdata.ih"

ostream &WIPdata::insert(ostream &out) const
{
    size_t endTime = time(0);

    out.setf(ios::fixed, ios::floatfield);
    out.precision(1);          // 1 digit behind the .

    insertRatings(out, 1, endTime, d_selfRatings);
    insertRatings(out, 2, endTime, d_metaRatings);

    for (size_t idx = 0; idx != Tools::N_OTHER; ++idx)
        insertRatings(out, 3, endTime, d_otherRatings[idx]);

    out.flush();

    return out;
}
