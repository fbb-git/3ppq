#include "psych.ih"

void Psych::verifyAck()
{
    LockGuard lg{ d_data.lg() };

    if (not get())
        return;

    d_display.append("email");

    uint16_t ack = Tools::valueOr(d_cgi.param1("ack"), 0);
    if (ack == 0 || ack != d_ack)
    {
        d_display.append({ "email", "mode", "pwd" });
        d_display.out("ackerror.h");
        return;
    }

    d_ack = 0;
    d_data.update(emailKey(), toString());

    d_display.out(
            "actions.h",
            {
                messages()
            }
        );
}



