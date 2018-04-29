#include "ratings.ih"

Ratings::Ratings(char const *filename)
:
    d_data(3, vector<double>(N_QUESTIONS) )
{
    ifstream in;
    Exception::open(in, filename);          // open the CSV file

    CSV4180 csv{ N_PRE + N_QUESTIONS };
    csv.read(in, N_LINES);                  // read required # lines

    cleanup(csv.release());
}
