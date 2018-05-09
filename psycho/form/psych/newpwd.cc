#include "psych.ih"

void Psych::newPwd()
{
    requireOneOf("email", "@");

    string pwd = newPassword();

    LockGuard lg{ d_data.lg() };

    if (not get())
        return;

    d_pwdHash = Tools::md5hash(pwd);
    d_data.update(emailKey(), toString());

    g_mailer.sendmail(
                d_eMail, 
                d_eMail, 
                "Nieuw wachtwoord 3ppq.nl",
                DollarText::replaceStream(
                    g_options.mailDir() + "newpwd",
                    {
                        d_name,
                        d_lastName,
                        pwd
                    }
                )
            );

    d_display.out("newpwd.h");
}




