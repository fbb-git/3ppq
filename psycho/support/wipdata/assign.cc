#include "wipdata.ih"

void WIPdata::assign(string &dest, vector<double> const &src)
{
    dest.resize(src.size());

    transform(src.begin(), src.end(), dest.begin(), 
        [&](double value)
        {
            return static_cast<int>(round(2 * value) + 3);
        }
    );
}
