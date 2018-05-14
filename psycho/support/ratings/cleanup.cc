#include "ratings.ih"

void Ratings::cleanup(vector< vector<string> > const &data)
{
    d_psychID = String::trim(data[0][0]);
    d_clientIdent = String::trim(data[0][1]);

    d_from = stoul(data[0][3]);
    d_until = stoul(data[0][4]);

    for (size_t idx = 0; idx != 2; ++idx)
    {
        if (data[idx][Tools::TYPE].find_first_of("12") == string::npos)
        {
            g_log << "data ordering corruped: line " << idx + 1 <<
                                ", expected 1 or 2, found " << 
                                data[idx][Tools::TYPE] << endl;
            throw Tools::NO_DATA;
        }

        transform(data[idx].begin() + Tools::N_PRE, data[idx].end(), 
                  d_data[idx].begin(), 
                      [&](string const &value)
                      {
                          return stod(value);
                      }
                  );
    }

    for (size_t idx = 2; idx != Tools::N_LINES; ++idx)
    {
        if (data[idx][Tools::TYPE].find("3") == string::npos)
        {
            g_log << "data ordering corruped: line " << idx + 1 <<
                     ", expected 3, found " << data[idx][Tools::TYPE] << endl;
            throw Tools::NO_DATA;
        }

        double *dest = &d_data[2][0];

        for_each(data[idx].begin() + Tools::N_PRE, data[idx].end(), 
            [&](string const &value)
            {
                *dest++ += stod(value) / (Tools::N_LINES - 2);
            }
        );
    }
}

