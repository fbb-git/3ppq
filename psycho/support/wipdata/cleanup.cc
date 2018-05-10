#include "wipdata.ih"

    // the test for value == '0' is used to allow reducing the questionnaires
    // for testing purposes.

// static
void WIPdata::cleanup(string &dest, string const &ratings)
{
    transform(ratings.begin(), ratings.end(), dest.begin(), 
        [&](char value)
        {
            return value == '0' ? 3 : value - '0';
        }
    );
}
