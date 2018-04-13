#include "psych.ih"

                            email       ackCheck.h  ack nonzero: enter ack

                            email       action.h    login OK

void Psych::login()
{
    if (not pwdMatch())
    {
        Tools::delay();
        d_display.out(g_options.html() + "pwderror");
        return;
    }

    if (d_ack != 0)                     // need to ack.
    {
        requestAck();
        return;
    }

    d_display.append("email");
    d_display.out(g_options.html() + "actions");    // logged in.
}
