#include "psychologist.ih"

void Psychologist::newRegistration()
{
    ofstream out(g_options.psychologists(), ios::in | ios::ate);

    out << 
        d_cgi.param1("name") << '\n' <<
        d_cgi.param1("email") << '\n' <<
        d_cgi.param1("nip") << '\n' <<
        d_cgi.param1("passwd") << '\n' <<
        d_cgi.param1("gender") << '\n';

    Display{ "newregistration" };
}
