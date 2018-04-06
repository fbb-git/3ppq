#include "mailer.ih"

void Mailer::sendmail(string const &to, string const &subject, 
                      string const &txt)
{
    istringstream text{ txt };
    
    CinInserter mail;
    mail.execute("/usr/bin/mail "//-r noreply@3ppq.nl
                     " -s '" + subject + "' " + to);

    mail << text.rdbuf();
    mail.stop();

    g_log << mail.ret() << ": e-mail (" << subject << ") sent to " << to << 
                                                                        '\n';
}






