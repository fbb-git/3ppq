#include "psychologist.ih"

// static
string Psychologist::toString(Record const &rec)
{
    ostringstream out;

    Tools::write(out, &rec.nr);                   // write binary values
    out.write(&rec.pwdHash.front(), 16);
    Tools::write(out, &rec.size);

    return out.str();
}
