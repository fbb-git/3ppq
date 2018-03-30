#include "psychologist.ih"

void Psychologist::alreadyRegistered()
{
    g_log << "Psych: registered " << d_cgi.param1("name") << endl;

    Display{ "alreadyregistered" };
}
