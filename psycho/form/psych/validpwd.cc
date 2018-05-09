#include "psych.ih"

bool Psych::validPwd() 
{
    if (pwdMatch())
        return true;

    Tools::delay();
    
    d_display.append("email");
    d_display.out(
        "actions.h",
        {
            R"_(
<h1>Wachtwoord onjuist</h1>
<hr>
Het opgegeven (huidig) wachtwoord is onjuist.
)_"
            }
    );
    return false;
}
