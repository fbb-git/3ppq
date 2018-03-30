#include "handler.ih"

void Handler::incompleteUnPw()
{
    g_log << "incomplete UN/PW" << endl;

    Display{"missingcredentials"};

    login();
}
