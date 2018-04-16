#include "psych.ih"

void Psych::requestAck()
{
    StrVector replacements{
                    d_name,             // $0
                    d_lastName,         // $1
                    to_string(d_ack)    // $2
                };

    g_mailer.sendmail(
                d_email, 
                "3ppq.nl verification",
                DollarText::replaceStream(
                                g_options.mail() + "requestack", replacements
                            ) 
            );

    d_display.append({ "email", "pwd", "mode" });
    d_display.out(g_options.html() + "requestack.h", replacements);
}
