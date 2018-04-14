#include "psych.ih"

// receives: e-mail, pwd, mode: noPwd or login

void Psych::verify()
{
    Tools::debug() << "state: verify" << endl;

    {
        LockGuard lg{ d_data.lg() };
        if (not get())
            return;
    }

    string mode = d_cgi.param1("mode");

    if (mode == "noPwd")
        confirmNewPwd();
    else if (mode == "login")
        login();
    else
        homePage();
}



