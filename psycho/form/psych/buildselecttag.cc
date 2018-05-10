#include "psych.ih"

void Psych::buildSelectTag(string *select, vector<bool> const &reportExists,
                           size_t idLength) const
{
    ostringstream out;

    startSelect(out, idLength);

    size_t idx = 0;
    bool foundReport = false;
    for (auto const &client: d_client)
    {
        foundReport |= reportExists[idx];

        out << setw(11) << ' ' << "<option value=" << idx << '>' <<
                fixedWidth(client.ident(), idLength) <<  
                (reportExists[idx] ? "R" : "&nbsp;") << ' ' <<
                client.name() <<  ' ' <<  client.lastName() << "</option>\n";
        ++idx;
    }

    endSelect(out, foundReport);

    *select = out.str();    
}


