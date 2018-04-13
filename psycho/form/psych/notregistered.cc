#include "psych.ih"

void Psych::notRegistered()
{
    g_log << "NIP `" << d_cgi.param1("email") << "' not registered" << endl;
    Tools::delay();

    Display{ g_options.html() + "notregistered" };
}
