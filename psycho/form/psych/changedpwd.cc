#include "psych.ih"

bool Psych::changedPwd()
{
    string newemail = d_cgi->param1("newemail");

    string newpwd = d_cgi->param1("newpwd");

    if (newpwd.length() > 0)
        d_pwdHash = Tools::md5hash(newpwd);

    if (newemail == d_eMail)                    // same key: update, else new
        d_data.update(emailKey(), toString());  // record.
    else
    {
        d_data.erase(emailKey());
        d_eMail = newemail;
                                                // update e-mail addresses
        std::vector<LockGuard> lg = updateWIPemail();       // in WIP files

        d_data.add(Tools::md5hash(d_eMail), toString());
    }

    if (newpwd.length() > 0)                // new password
    {                                       // new login
        d_display.out("psychpage.h");
        return true;
    }

    return false;
}
