#include "clientpage.ih"

void ClientPage::buildSelectTag(string *select, size_t idLength) const
{
    ostringstream out;

    startSelect(out, idLength);

    size_t idx = 0;
    bool foundReport = false;
    for (auto const &client: d_clients)
    {
        foundReport |= d_reportExists[idx];

        out << setw(11) << ' ' << "<option value=" << idx << '>' <<
                fixedWidth(client.ident(), idLength) <<  
                (d_reportExists[idx] ? "R" : "&nbsp;") << ' ' <<
                client.name() <<  ' ' <<  client.lastName() << "</option>\n";
        ++idx;
    }

    endSelect(out, foundReport);

    *select = out.str();    
}


