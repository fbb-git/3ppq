#include "mailer.ih"

void Mailer::sendmail(string to, string const &subject, 
                      string const &txt)
{
    string mailRequest = g_config.findKeyTail("mail:");

    if (mailRequest == "log")
    {
        Tools::stdLog() << "would have sent mail to `" << to << 
                    "', subject: `" << subject << "', contents: `" << txt <<
                    '\'' << endl; 
        return; 
    }

    if (mailRequest == "off")
        return;

    if (mailRequest.find('@') != string::npos)
    {
        Tools::stdLog() << "mail to " << to << " is sent to " << 
                            mailRequest << endl;
        to = mailRequest;
    }

    istringstream text{ txt };
    
    string replyTo{ g_config.findKeyTail("replyTo:") };
    if (not replyTo.empty())
        replyTo.insert(0, "-r ");

    CinInserter mail;
    mail.execute("/usr/bin/mail " + replyTo + " -s '" + subject + "' " + to);

    mail << text.rdbuf();
    mail.stop();

    Tools::stdLog() << "mail (" << subject << ") sent to " << to << 
                       ", return code: " << mail.ret() << endl;
}






