#include "psych.ih"

void Psych::requestAck()
{
    StrVector replacements{
                    d_name,             // $0
                    d_lastName,         // $1
                    to_string(d_ack)    // $2
                };

    g_mailer.sendmail(
                d_eMail, 
                d_eMail, 
                "Activatie 3ppq.nl account",
                DollarText::replaceStream(
                                g_options.mailDir() + "requestack", 
                                replacements
                            ) 
            );

    d_display.append({ "email", "pwd", "mode" });
    d_display.out("requestack.h", replacements);
}
