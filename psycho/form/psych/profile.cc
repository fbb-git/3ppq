#include "psych.ih"

void Psych::profile()
{
    LockGuard lg { d_data.lg() };

    if (not get())
        return;

    if (d_cgi.param1("email") != d_email)
    {
        d_display.homePage();
        return;
    }

    if (not pwdMatch())
    {
        Tools::delay();
        
        d_display.append("email");
        d_display.out(
            "actions.h",
            {
                R"(
<h1>Wachtwoord onjuist</h1>
<hr>
Het opgegeven (huidig) wachtwoord is onjuist.
)"
            }
        );
        return;
    }

    uint8_t field;
    if (not validProfileData(&field))
    {
        d_display.append("email");
        d_display.out(
            "actions.h",
            {
                R"(
<h1>Profiel wijzigingen zijn niet verwerkt</h1>

De nieuwe gegevens van uw profiel konden niet worden verwerkt.<br>
Controleer met name uw NIP-nummer en e-mail adres.<br>
Ook dient een eventueel nieuw wachtwoord twee keer te zijn vermeld.
<p>
)"
            }
        );
        return;
    }

    string newemail = d_cgi.param1("newemail");
    d_name          = d_cgi.param1("name");
    d_lastName      = d_cgi.param1("lastName");
    d_field         = field;

    string newpwd = d_cgi.param1("newpwd");

    if (newpwd.length() > 0)
        d_pwdHash = Tools::md5hash(d_cgi.param1("newpwd"));

    if (newemail == d_email)                    // same key: update, else new
        d_data.update(emailKey(), toString());  // record.
    else
    {
        d_data.erase(emailKey());
        d_email = newemail;
        d_data.add(Tools::md5hash(d_email), toString());
    }
    
    if (newpwd.length() > 0)                // new password
    {                                       // new login
        d_display.out("psychpage.h");
        return;
    }
   
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

