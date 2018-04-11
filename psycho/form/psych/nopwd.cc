#include "psych.ih"

void Psych::noPwd()
{
    string newPwd = newPassword();

    LockGuard lg{ d_data.lg() };

    if (not get())
        return;

    d_pwdHash = Tools::md5hash(newPwd);
    d_data.update(nipKey(), toString());

    g_mailer.sendmail(
                d_email, 
                "3ppq.nl wijziging",
                DollarText{ g_options.mail() + "nopwd", 
                    {
                        genderText(),               // $0
                        d_lastName,                 // $1
                        newPwd                      // $2
                    }
                }.text() 
            );

    Display{ g_options.html() + "nopwd" };
}
