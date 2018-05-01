#include "psych.ih"

void Psych::buildSelectTag(string *select, size_t idLength) const
{
    ostringstream out;

    startSelect(out, idLength);

    size_t idx = 0;
    for (auto const &client: d_client)
    {
        out << setw(11) << ' ' << "<option value=" << idx++ << '>' <<
                fixedWidth(client.ident(), idLength, Tools::RIGHT) << ' ' << 
                client.name() << ' ' << client.lastName() << "</option>\n";
    }

    endSelect(out);

    *select = out.str();    
}
