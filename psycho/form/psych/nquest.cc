#include "psych.ih"

void Psych::nQuest()
{
    ofstream out(g_options.dataDir() + "nq");
    out << d_cgi->param1("nq") << '\n';

    d_display.homePage();
}
