#include "psych.ih"

void Psych::verifyAck()
{
    LockGuard lg{ d_data.lg() };

    if (not get())
        return;

    uint16_t ack = Tools::valueOr(d_cgi.param1("ack"), 0);
    if (ack == 0 || ack != d_ack)
    {
        Display{
            {
                Tools::passParam(d_cgi, "nip"),
                Tools::passParam(d_cgi, "pwd")
            },
            g_options.html() + "ackerr" 
        };
        return;
    }

    d_ack = 0;
    d_data.update(nipKey(), toString());

    Display{ g_options.html() + "actions" };
}



