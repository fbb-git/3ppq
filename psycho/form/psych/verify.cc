#include "psych.ih"

    // page opened when the psychologist 
void Psych::verify()
{
    string data;
    {
        LockGuard lg{ d_lockPath, d_lockFd };
        d_psychData.get(&data, nipKey());
    }

    if (data.empty())
    {
        g_log << "verify: unknown NIP" << endl;
        this_thread::sleep_for(chrono::seconds(5));
        Display{ g_options.html() + "unknownpsych" };
        return;
    }

    getUnencrypted(data);

    if (not pwdMatch())
    {
        this_thread::sleep_for(chrono::seconds(5));
        g_log << "verify: incorrect passwd" << endl;
        Display{ g_options.html() + "pwdfailure" };
        return;
    }

    if (d_record.ack != 0)
    {
        getPrivate(data, 8 + d_record.size);
        g_log << "verify: mail should be sent to " << d_private.email << 
                " (temp. sent to frank@localhost)" << endl;

        StrVector sv{
                        d_private.genderText(),     // $0
                        d_private.lastName,         // $1
                        to_string(d_record.ack)     // $2
                    };

        Mailer mailer;
        mailer.sendmail(
                    "frank@localhost", 
                    "3ppq.nl verification",
                    DollarText{ g_options.mail() + "verify", sv }.text() 
                );

        Display{
            {
                passParam("nip"),
                passParam("pwd"),
            },
            g_options.html() + "verify", &sv };
        return;
    }

    g_log << "actions" << endl;

    Display{ g_options.html() + "actions" };
}



