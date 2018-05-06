#include "psych.ih"

void Psych::notRegistered()
{
    Tools::debug() << "notRegistered: `" << d_cgi->param1("email") << '\'' << 
                                                                        endl;
    Tools::delay();
    d_display.out("notregistered.h");
}
