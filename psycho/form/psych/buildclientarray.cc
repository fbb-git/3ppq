#include "psych.ih"

size_t Psych::buildClientArray(string *array, 
                               vector<bool> &reportExists) const
{
    size_t idLength = 0;
    for (auto const &client: d_client)
        idLength = ::max(idLength, client.ident().length());
    ++idLength;


    string pid = to_string(d_ID);
    string reportPre = g_options.reportsDir() + pid + '.';

    ostringstream out;

    for (auto const &client: d_client)      // construct the client array
    {
//    g_log << client.id() << ": active = " << client.active() << 
//                            ", login0 = " << client.login0() << endl;

        ifstream in{ reportPre + client.ident() + ".pdf" };
        reportExists.push_back(
                        Tools::rwExists(reportPre + client.ident() + ".pdf")
                    );

        out << setw(11) << "[\"" <<   
                client.ident()      << "\","    <<      //  0
                client.gender()     << ','      <<      //  1
                client.active()     << ",\""    <<      //  2
                client.name()       << "\",\""  <<      //  3
                client.lastName()   << "\",\""  <<      //  4
                client.email()      << "\","    <<      //  5
                reportExists.back() << "],\n";          //  6
    }
    *array = out.str();

    return idLength;
}

