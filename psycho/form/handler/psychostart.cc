#include "handler.ih"

void Handler::psychoStart()
{
    g_log << d_state << ": psychoStart" << endl;

    Display{"psychostart"};                 // show the psychostart page
}
