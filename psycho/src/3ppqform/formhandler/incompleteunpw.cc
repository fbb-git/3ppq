#include "formhandler.ih"

void FormHandler::incompleteUnPw()
{
    g_log << "incomplete UN/PW" << endl;

    Display{"missingcredentials"};

    login();
}
