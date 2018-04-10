
#include "psych.ih"

    // page opened when the psychologist 
void Psych::verify()
{
    LockGuard lg{ d_lockPath, d_lockFd };

    string data;
    if (data = getData(); data.empty())     // getData calls Display on error
        return;

    if (not pwdMatch())
    {
//        this_thread::sleep_for(chrono::seconds(5));
        g_log << "verify: incorrect passwd" << endl;

        Display{ g_options.html() + "pwdfailure" };
        return;
    }

//FBB: TMP
//d_private.get(data.substr(0, 8), data.substr(8 + d_record.size));

    if (d_record.ack != 0)
    {
        // getPrivate(data, 8 + d_record.size);
        d_private.get(data.substr(0, 8), data.substr(8 + d_record.size));

        g_log << "verify: ack. " << d_record.ack << 
                " to send to " << d_private.email() << 
                " (temp. not sent)" << endl;

        StrVector sv{
                        d_private.genderText(),     // $0
                        d_private.lastName(),       // $1
                        to_string(d_record.ack)     // $2
                    };

//        Mailer mailer;
//        mailer.sendmail(
//                    d_private.email(), 
//                    "3ppq.nl verification",
//                    DollarText{ g_options.mail() + "verify", sv }.text() 
//                );

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



