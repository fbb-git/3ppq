#include "psych.ih"

string Psych::Record::toString() const
{
    ostringstream out;

    Tools::write(out, &time);
    Tools::write(out, &ack);
    Tools::write(out, &flags);
    Tools::write(out, &nr);
    Tools::write(out, pwdHash);

    return out.str();
}
