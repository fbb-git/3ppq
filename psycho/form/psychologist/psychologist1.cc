#include "psychologist.ih"

Psychologist::Psychologist(CGI &cgi)
:
    d_path(g_options.psychologists()),
    d_cgi(cgi),
    d_psychData(d_path)
{}
