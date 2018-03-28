#include "formhandler.ih"

void FormHandler::psychoStart()
{
    g_log << d_state << ": psychoStart" << endl;

    Display{"psychostart"};                 // show the psychostart page
}
