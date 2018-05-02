#include "ratings.ih"

Ratings::Ratings(char const *filename)
:
    d_data(3, vector<double>(Tools::N_QUESTIONS) )
{
    ifstream in;
    Exception::open(in, filename);          // open the CSV file

    CSV4180 csv{ Tools::N_PRE + Tools::N_QUESTIONS };
    csv.read(in, Tools::N_LINES);           // read required # lines

    cleanup(csv.release());
}
