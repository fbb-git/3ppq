#include "psych.ih"

void Psych::confirmNewPwd()
{
    d_display.append("email");              // pass the e-mail variable
    d_display.out(g_options.html() + "confirmnewpwd");
}
