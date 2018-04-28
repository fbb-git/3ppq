#include "psych.ih"

    // at least some clients are available.

void Psych::infoClient(string *array, string *select)
{
    size_t idLength = 0;
    for (auto const &client: d_client)
        idLength = ::max(idLength, client.ident().length());
    idLength += 2;


    ostringstream out;
    for (auto const &client: d_client)      // construct the client array
    {
//    g_log << client.id() << ": active = " << client.active() << 
//                            ", login0 = " << client.login0() << endl;

        out << setw(11) << "[\"" <<   
                client.ident()      << "\","    <<      //  0
                client.gender()     << ','      <<      //  1
                client.active()     << ",\""    <<      //  2
                client.name()       << "\",\""  <<      //  3
                client.lastName()   << "\",\""  <<      //  4
                client.email()      << "\"],\n";        //  5
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
            <span class=courier18 style='margin-left: 4px' ><b>)" << fixedWidth("ID", idLength) <<
            R"(&nbsp;Naam</b>
            </span><br>
            <select class=clientSelect id=selectID onclick='process("show")'
                     size=)" << nRows << ">\n";

    size_t idx = 0;
    for (auto const &client: d_client)
        out << setw(11) << ' ' << "<option value=" << idx++ << '>' <<
                fixedWidth(client.ident(), idLength) << ' ' << 
                client.name() <<  ' ' <<  client.lastName() << "</option>\n";

    out << R"(
            </select>
        </div>
    </td>
    <td class=topAlign>    
        <div class=float> 
            &nbsp;
            <p>
            (klik op een client in het linker overzicht<br>
             om de clientgegevens te zien of te wijzigen)<br>
        </div>
    </td>
    </tr>
    </table>
)";

    *select = out.str();    
}



