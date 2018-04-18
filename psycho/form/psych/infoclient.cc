#include "psych.ih"

    // at least some clients are available.

void Psych::infoClient(string *array, string *vars, string *select)
{
    size_t nameLength = 0;
    for (auto const &client: d_client)
        nameLength = ::max(nameLength, client.d_name.length());
    nameLength += 2;


    for (auto const &client: d_client)      // construct the client array
    {
        ostringstream out;

        out << setw(11) << '[' <<   
                client.id()         << ','      << 
                client.activeTime() << ",\""'   <<
                client.name()       << "\",\""  << 
                client.lastName()   << "\",\""  << 
                client.email()      << "\"],\n";

        *array = out.str();
    }

    ostringstream out;                          // construct the variables
    out << setw(7) << ' ' << "var nextID = " << d_nextClientID  << ";\n" <<
           setw(7) << ' ' << "var login0 = " << 
                                        Tools::random(10, 99)   << ";\n";
    *vars = out.str();

    out.str("");

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
                ::min(d_client.size(), MAX_CLIENT_SELECT_ROWS) << ">\n";

    for (auto const &client: d_client)
        out << setw(11) << ' ' << "<option value=" << client.id() << '>' <<
                fixedWidth(client.id(), 3, right) << ' ' << 
                fixedWidth(client.name(), nameLength) << ' ' <<
                client.lastName() << "</option>";

    out << R"(
            </select>
        </div>
    </td>
    <td class=topAlign>    
        <div class=float> 
            &nbsp;
            <p>
            <input type=submit value=Verwijder onclick='remove()'><br>
            (verwijdert gemarkeerde cli&euml;nten)<br>
        </div>
    </td>
    </tr>
    </table>
)";

    *select = out.str();    
}



