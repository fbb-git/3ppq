#include "psychologist.ih"

// static
stringstream Psychologist::toString(Private const &private)
{
    stringstream out;

    Tools::write(out, &private.nip);                // write binary value
    Tools::write(out, &private.gender, 1);

    out <<  private.name        << '\n' <<          // write text values
            private.lastName    << '\n' <<
            private.email       << '\n';

    return out;                                     // return stringstream
}
