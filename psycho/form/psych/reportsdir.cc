#include "psych.ih"

void Psych::reportsDir(string const &pwd) const
{
    Tools::mkdir( g_options.reportsDir() + to_string(d_ID) );
}
