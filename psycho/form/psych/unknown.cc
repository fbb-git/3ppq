#include "psych.ih"

void Psych::unknown()
{
    g_log << "NIP `" << d_cgi.param1("nip") << "' not registered" << endl;
//        this_thread::sleep_for(chrono::seconds(5));
    Display{ g_options.html() + "unknownpsych" };
}
