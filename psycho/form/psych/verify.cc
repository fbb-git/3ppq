#include "psych.ih"

    // page opened when the psychologist 
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


    if (d_ack != 0)
    {
        g_log << "verify: ack. " << d_ack << 
                " to send to " << d_email << 
                " (temp. not sent)" << endl;

        StrVector replacements;

        d_dollarText += genderText();        // $0
        d_dollarText += d_lastName;          // $1
        d_dollarText += to_string(d_ack);   // $2

        g_mailer.sendmail(
                    d_email, 
                    "3ppq.nl verification",
                    d_dollarText.replace(replacements, 
                                         g_options.mail() + "verify") 
                );

        d_display.append("nip");
        d_display.append("pwd");

        d_display.useReplacements(replacements);
        d_display.out(g_options.html() + "verify");

        return;
    }

    d_display.append("nip");
    d_display.out(g_options.html() + "actions");
}



