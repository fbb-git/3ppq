#include "psych.ih"

void Psych::confirmNewPwd()
{
    Tools::debug() << "confirmnewpwd.h" << endl;

    d_display.append("email");              // pass the e-mail variable
    d_display.out("confirmnewpwd.h");
}
