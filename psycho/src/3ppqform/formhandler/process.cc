#include "formhandler.ih"

void FormHandler::process()
{
    g_log << "Starting FormHandler::process" << endl;

    if (d_logout)
        d_state = LOGOUT;

    (this->*s_handler[d_state]) ();     // Initial state is login: see the 
                                        // login function.
}
