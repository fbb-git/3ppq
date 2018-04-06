#include <iostream>
#include <string>

#include <bobcat/log>

#include "../mailer.h"

using namespace std;
using namespace FBB;

Log g_log{ "logfile" };

int main()
try
{
    Mailer mailer;

    mailer.sendmail("frank@localhost", "support driver",
        "\n"
        "This is mail from support/mailer/driver\n"
    );
}
catch (...)
{
    return 1;
}
