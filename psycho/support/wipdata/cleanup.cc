#include "wipdata.ih"

// static
void WIPdata::cleanup(string &dest, string const &ratings)
{
    transform(ratings.begin(), ratings.end(), dest.begin(), 
        [&](char value)
        {
            return value - '0';
        }
    );
}
