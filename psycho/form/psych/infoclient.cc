#include "psych.ih"

    // at least some clients are available.

void Psych::infoClient(string *array, string *select)
{
    size_t nameLength = 0;
    for (auto const &client: d_client)
        nameLength = ::max(nameLength, client.name().length());
    nameLength += 2;


    ostringstream out;
    for (auto const &client: d_client)      // construct the client array
    {
//    g_log << client.id() << ": active = " << client.active() << 
//                            ", login0 = " << client.login0() << endl;

        out << setw(11) << '[' <<   
                client.id()         << ','      <<      //  0
                client.gender()     << ','      <<      //  1
                client.active()     << ','      <<      //  2
                client.login0()     << ",\""    <<      //  3
                client.name()       << "\",\""  <<      //  4
                client.lastName()   << "\",\""  <<      //  5
                client.email()      << "\"],\n";        //  6
    }
    *array = out.str();

    size_t nRows = std::max(Tools::min(d_client.size(), 
                                       Tools::MAX_CLIENT_SELECT_ROWS),
                            2UL);
    
    out.str("");                      // construct the select tag
    out << R"(
    <table>
    <tr>
    <td>
        <div class=leftFloat>
            <span class=courier18><b>
            &nbsp;ID )" << fixedWidth("Naam", nameLength) << R"(Achternaam</b>
            </span><br>
            <select class=clientSelect id=selectID onclick='update()' size=)" 
                                                                            <<
                nRows << ">\n";

    size_t idx = 0;
    for (auto const &client: d_client)
        out << setw(11) << ' ' << "<option value=" << idx++ << '>' <<
                fixedWidth(to_string(client.id()), 3, Tools::RIGHT) << ' ' << 
                fixedWidth(client.name(), nameLength) << ' ' <<
                client.lastName() << "</option>\n";

    out << R"(
            </select>
        </div>
    </td>
    <td class=topAlign>    
        <div class=float> 
            &nbsp;
            <p>
            <input type=submit value=Verwijder onclick='remove()'><br>
            (verwijdert de gemarkeerde cli&euml;nt)<br>
        </div>
    </td>
    </tr>
    </table>
)";

    *select = out.str();    
}



