#include "psych.ih"

void Psych::profile()
{
    LockGuard lg { d_data.lg() };

    if (not get())
        throw false;

    requireEqual("email", d_eMail);

    if (not validPwd())
        return;

    uint8_t field;
    if (not validProfileData(&field))
        return;

    d_name          = d_cgi->param1("name");
    d_lastName      = d_cgi->param1("lastName");
    d_field         = field;

    if (changedPwd())                   // new pwd requires new login
        return;                         // also: update e-mail      

   
    d_display.append("email");
    d_display.out(
        "actions.h",
        {
            R"(
<h1>Uw profiel is aangepast</h1>
)"
        }
    );
}

