#include "handler.ih"

void Handler::autoLogout()
{
    g_log << d_state << ": autologout" << endl;

    Display{"autologout"};

    d_state = VERIFY_UNPW;
}
