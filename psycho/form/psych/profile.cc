#include "psych.ih"

void Psych::profile()
{
    d_display.append("email");
    d_display.out(g_options.html() + "actions.h");
}
