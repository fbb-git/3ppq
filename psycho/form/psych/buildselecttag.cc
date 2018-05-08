#include "psych.ih"

void Psych::buildSelectTag(string *select, vector<bool> const &reportExists,
                           size_t idLength) const
{
    ostringstream out;

    startSelect(out, idLength);

    size_t idx = 0;
    for (auto const &client: d_client)
    {
        out << setw(11) << ' ' << "<option value=" << idx << '>' <<
                fixedWidth(client.ident(), idLength) <<  
                (reportExists[idx] ? "R" : "&nbsp;") << ' ' <<
                client.name() <<  ' ' <<  client.lastName() << "</option>\n";
        ++idx;
    }

    endSelect(out, reportExists);

    *select = out.str();    
}


