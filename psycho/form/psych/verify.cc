#include "psych.ih"


void Psych::verify()
{
    {
        LockGuard lg{ d_data.lg() };
        if (not get())
            return;
    }

    if (not pwdMatch())
    {
        Tools::delay();
        d_display.out(g_options.html() + "pwdfailure");
        return;
    }


    if (d_ack == 0)
    {
        d_display.append("nip");
        d_display.out(g_options.html() + "actions");
        return;
    }

    StrVector replacements{
                    genderText(),       // $0
                    d_lastName,         // $1
                    to_string(d_ack)    // $2
                };

    g_mailer.sendmail(
                d_email, 
                "3ppq.nl verification",
                DollarText::replaceStream(
                                g_options.mail() + "verify", replacements
                            ) 
            );

    d_display.append({"nip", "pwd"});
    d_display.out(g_options.html() + "verify", replacements);
}



