#include <iostream>
#include <string>

// #include <thread>

#include <bobcat/log>
#include <bobcat/fork>
#include <bobcat/configfile>

#include "../mailer.h"

using namespace std;
using namespace FBB;

ConfigFile g_config;

Log g_log{ "logfile" };

class MailFork: public Fork
{
    private:
        void childProcess() override;
        void parentProcess() override;
};

void MailFork::childProcess()
{
    prepareDaemon();

//    this_thread::sleep_for(chrono::seconds(5));

    Mailer mailer;

    mailer.sendmail("frank@localhost", "frank@localhost", "support driver",
        "\n"
        "This is mail from support/mailer/driver\n"
    );
}

void MailFork::parentProcess()
{}
    
int main()
try
{
    MailFork mailFork;
    mailFork.fork();

}
catch (...)
{
    cerr << "caught exception\n";
    return 1;
}

