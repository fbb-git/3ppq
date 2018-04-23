#include "psych.ih"

void Psych::login()
{
    if (not pwdMatch())
    {
        Tools::delay();
        d_display.out("pwderror.h");
        return;
    }

    if (d_ack != 0)                                     // need to ack.
    {
        requestAck();
        return;
    }

    d_display.append("email");
    d_display.out(
        "actions.h",
        {
            messages()
        }
    );      // logged in.
}
