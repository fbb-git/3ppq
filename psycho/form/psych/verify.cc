#include "psych.ih"

    // page opened when the psychologist 
void Psych::verify()
{
    {
        LockGuard lg{ d_lockPath, d_lockFd };
        if (not get())
            return;
    }

    if (not pwdMatch())
    {
        Tools::delay();
        Display{ g_options.html() + "pwdfailure" };
        return;
    }


    if (d_ack != 0)
    {
        g_log << "verify: ack. " << d_ack << 
                " to send to " << d_email << 
                " (temp. not sent)" << endl;

        StrVector sv{
                        genderText(),       // $0
                        d_lastName,         // $1
                        to_string(d_ack)    // $2
                    };

        g_mailer.sendmail(
                    d_email, 
                    "3ppq.nl verification",
                    DollarText{ g_options.mail() + "verify", sv }.text() 
                );

        Display{
            {
                Tools::passParam(d_cgi, "nip"),
                Tools::passParam(d_cgi, "pwd"),
            },
            g_options.html() + "verify", &sv };

        return;
    }

    Display{
            {
                Tools::passParam(d_cgi, "nip"),
            },
            g_options.html() + "actions" };
}



