
#include "handler.ih"

void Handler::login()
{
    g_log << d_state << ": login" << endl;

    Display{"login"};

    d_state = VERIFY_UNPW;
}
