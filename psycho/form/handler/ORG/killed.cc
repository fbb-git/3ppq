#include "handler.ih"

void Handler::killed()
{
    g_log << d_state << ": killed" << endl;

    Display{"killed"};

    d_state = VERIFY_UNPW;
}
