#include "psych.ih"

string Psych::publicData() const
{
    ostringstream out;

    uint16_t value = Tools::random(8999) + 1000;    // 1000 .. 9999
    Tools::write(out, &value);

    value = identNr();
    Tools::write(out, &value);

    Tools::write(out, Tools::md5hash(d_cgi.param1("pwd")));

    return out.str();
}
