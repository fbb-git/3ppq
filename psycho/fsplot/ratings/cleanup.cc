#include "ratings.ih"

void Ratings::cleanup(vector< vector<string> > const &data)
{
    d_psychID = String::trim(data[0][0]);
    d_clientIdent = String::trim(data[0][1]);

    for (size_t idx = 0; idx != 2; ++idx)
    {
        if (data[idx][TYPE].find_first_of("12") == string::npos)
            throw Exception{} << "data ordering corruped: line " << idx + 1 <<
                                ", expected 1 or 2, found " << 
                                data[idx][TYPE];

        transform(data[idx].begin() + N_PRE, data[idx].end(), 
                  d_data[idx].begin(), 
                      [&](string const &value)
                      {
                          return stod(value);
                      }
                  );
    }

    for (size_t idx = 2; idx != N_LINES; ++idx)
    {
        if (data[idx][TYPE].find("3") == string::npos)
            throw Exception{} << "data ordering corruped: line " << idx + 1 <<
                                ", expected 3, found " << data[idx][TYPE];

        double *dest = &d_data[2][0];

        for_each(data[idx].begin() + N_PRE, data[idx].end(), 
            [&](string const &value)
            {
                *dest++ += stod(value) / (N_LINES - 2);
            }
        );
    }
}

