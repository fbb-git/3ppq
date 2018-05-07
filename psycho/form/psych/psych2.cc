#include "psych.ih"

Psych::Psych(CGI &cgi)
:
    d_data(g_options.psych()),
    d_cgi(&cgi),
    d_display(cgi)
{}
