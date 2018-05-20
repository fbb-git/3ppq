#include "clientpage.ih"

size_t ClientPage::buildClientArray(string *array)
{
    size_t idLength = 0;

    for (auto const &client: d_clients)
        idLength = ::max(idLength, client.ident().length());

    ++idLength;

    string pid = to_string(d_ID);
    string reportPre = g_options.reportsDir() + pid + '.';

    ostringstream out;

    size_t idx = 0;
    for (auto const &client: d_clients)     // construct the client array
    {
//    g_log << client.id() << ": active = " << client.active() << 
//                            ", login0 = " << client.login0() << endl;

        if (client.active() and not WIPdata::exists(d_ID, client.ident()))
        {
            g_log << "deactivating client " << 
                     d_ID << '.' << client.ident() << ": no WIPdata" << endl;

            WIPdata::remove(d_ID, client.ident());
            d_deactivated.push_back(idx);
        }
        ++idx;

        ifstream in{ reportPre + client.ident() + ".pdf" };
        d_reportExists.push_back(
                        Tools::rwExists(reportPre + client.ident() + ".pdf")
                    );

        out << setw(11) << "[\"" <<   
                client.ident()      << "\","    <<      //  0
                client.gender()     << ','      <<      //  1
                client.active()     << ",\""    <<      //  2
                client.name()       << "\",\""  <<      //  3
                client.lastName()   << "\",\""  <<      //  4
                client.eMail()      << "\","    <<      //  5
                d_reportExists.back() << "],\n";          //  6
    }
    *array = out.str();

    return idLength;
}

