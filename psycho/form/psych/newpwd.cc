#include "psych.ih"

void Psych::newPwd()
{
    string pwd = newPassword();

    LockGuard lg{ d_data.lg() };

    if (not get())
        return;

    d_pwdHash = Tools::md5hash(pwd);
    d_data.update(emailKey(), toString());

    g_mailer.sendmail(
                d_email, 
                d_email, 
                "3ppq.nl wijziging",
                DollarText::replaceStream(
                    g_options.mail() + "newpwd",
                    {
                        d_name,
                        d_lastName,
                        pwd
                    }
                )
            );

    d_display.out(g_options.html() + "newpwd.h");
}




