#include "mailer.ih"

void Mailer::childProcess()
{
    prepareDaemon();

    istringstream txt{ d_txt };
    
    string replyTo{ g_config.findKeyTail("replyTo:") };
    if (not replyTo.empty())
        replyTo.insert(0, "-r ");

    CinInserter mail;
    mail.execute("/usr/bin/mail " + replyTo + " -s '" + 
                    d_subject + "' " + d_to);

    mail << txt.rdbuf();
    mail.stop();

    throw Tools::ForkChild::DONE;
}
