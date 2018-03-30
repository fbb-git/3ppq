#include "handler.ih"

void Handler::verifyUnPw()
{
    g_log << d_state << ":verify UN/PW" << endl;

    if (d_uName.empty() and d_pwd.empty())      // no UN/PW: try again
    {
        login();                                // state: VERIFY_UNPW
        return;
    }

    if (d_uName.empty() or d_pwd.empty())
    {
        incompleteUnPw();                       // state: LOGIN
        return;
    }

    monitorUnPwCheck();                         // state: LOGIN or CMD
}



