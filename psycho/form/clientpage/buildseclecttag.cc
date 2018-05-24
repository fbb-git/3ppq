#include "clientpage.ih"

void ClientPage::buildSelectTag(string *select, size_t idLength) const
{
    ostringstream out;

    startSelect(out, idLength);

    size_t idx = d_clients.size();
    bool foundReport = false;

    if (idLength < 10)      // at least 'Client ID ' long
        idLength = 10;

    for (
        auto client = d_clients.crbegin(), done = d_clients.crend(); 
            client != done;
                ++client
    )
    {
        --idx;

        foundReport |= d_reportExists[idx];

        out << setw(11) << ' ' << "<option value=" << idx << '>' <<
                fixedWidth(client->ident(), idLength, Tools::RIGHT) <<  
                (d_reportExists[idx] ? "R" : "&nbsp;") << ' ' <<
                client->name() <<  ' ' <<  client->lastName() << "</option>\n";
    }

    endSelect(out, foundReport);

    *select = out.str();    
}


