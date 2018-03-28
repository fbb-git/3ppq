#include "formhandler.ih"

void FormHandler::killed()
{
    g_log << d_state << ": killed" << endl;

    Display{"killed"};

    d_state = VERIFY_UNPW;
}
