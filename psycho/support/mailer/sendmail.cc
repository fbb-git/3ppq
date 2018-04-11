#include "mailer.ih"

void Mailer::sendmail(string to, string const &subject, 
                      string const &txt)
{
    string mailRequest = g_config.findKeyTail("mail:");

    if (mailRequest == "send" or mailRequest.empty())
    {
        if (mailRequest == "log")
            g_log << "would have sent mail to `" << to << "', subject: `" <<
                    subject << "', contents: `" << txt.substr(0, 20) << 
                    '\'' << endl; 
        else if (mailRequest.find('@' != string::npos))
            to = mailRequest;
        else 
        {
            if (mailRequest != "off")
                g_log << "ignoring config-file specification `mail: " << 
                            mailRequest << '\'' << endl;
            return;
        }
    }

    istringstream text{ txt };
    
    string replyTo{ "-r " + g_config.findKeyTail("mail:") };
    if (replyTo.length() > 3)
        replyTo.clear();

    CinInserter mail;
    mail.execute("/usr/bin/mail " + replyTo + " -s '" + subject + "' " + to);

    mail << text.rdbuf();
    mail.stop();

    g_log << "mail (" << subject << ") sent to " << to << 
                                ", return code: " << mail.ret() << endl;
}






