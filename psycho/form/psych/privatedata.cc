#include "psych.ih"

string Psych::privateData() const
{
    ostringstream out;

    uint64_t value = stoull(d_cgi.param1("nip"));
    Tools::write(out, &value);

    char var = d_cgi.param1("gender") == "M";
    out.put(var);

    out <<  d_cgi.param1("name")        << '\n' <<
            d_cgi.param1("lastName")    << '\n' <<
            d_cgi.param1("email")       << '\n';

    return out.str();
}