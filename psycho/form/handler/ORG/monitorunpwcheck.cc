#include "handler.ih"

void Handler::monitorUnPwCheck()
{
                            // send this command to the monitor: requesting
                            // verification of uname and pwd
    monitorSubmit() << "? " << d_uName << ' ' << d_pwd;

    g_log << "monitorUnPwCheck: reply = " << d_reply << endl;

    try
    {
        d_uid = stoul(d_reply);
        firstPage();                // show the first page for this user
    }
    catch (...)
    {
        if (d_reply[0] == '?')
            unknownUser();
        else
            alreadyLoggedIn();
    }
}
