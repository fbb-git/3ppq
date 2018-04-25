#include "wipdata.ih"

void  WIPdata::insertRatings(ostream &out, int type, size_t endTime,
                             string const &ratings) const
{
    out <<
        setw(3) << d_psychID <<         ',' <<
        setw(3) << d_clientID <<        ',' <<
        setw(2) << d_type <<            ',' <<
        setw(10)<< d_start <<           ',' <<
        setw(10)<< endTime;

    for (size_t idx = 0; idx != Tools::N_QUESTIONS; ++idx)
        out << ", " << setw(4) << ((ratings[idx] - 3) / 2.);

    out << '\n';
}
