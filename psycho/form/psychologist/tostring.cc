#include "psychologist.ih"

// static
stringstream Psychologist::toString(Private const &priv)
{
    stringstream out;

    Tools::write(out, &priv.nip);                   // write binary value
    Tools::write(out, &priv.gender, 1);

    out <<  priv.name        << '\n' <<             // write text values
            priv.lastName    << '\n' <<
            priv.email       << '\n';

    return out;                                     // return stringstream
}
