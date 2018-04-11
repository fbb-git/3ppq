#include "psych.ih"

void Psych::unknown()
{
    g_log << "NIP `" << d_cgi.param1("nip") << "' not registered" << endl;
    Tools::delay();

    Display{ g_options.html() + "unknownpsych" };
}
