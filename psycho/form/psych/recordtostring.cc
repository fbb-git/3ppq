#include "psych.ih"

string Psych::Record::toString() const
{
    ostringstream out;

    Tools::write(out, &ack);
    Tools::write(out, &nr);
    Tools::write(out, pwdHash);

    return out.str();
}
