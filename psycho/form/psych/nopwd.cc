#include "psych.ih"

void Psych::noPwd()
{
    string newPwd = newPassword();

    LockGuard lg{ d_data.lg() };

    if (not get())
        return;

    d_pwdHash = Tools::md5hash(newPwd);
    d_data.update(nipKey(), toString());

    d_dollarText += genderText();
    d_dollarText += d_lastName;
    d_dollarText += newPwd;
    
    g_mailer.sendmail(
                d_email, 
                "3ppq.nl wijziging",
                d_dollarText.replace(g_options.mail() + "nopwd")
            );

    d_display.out(g_options.html() + "nopwd");
}
