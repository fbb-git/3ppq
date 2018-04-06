#include "psych.ih"

void Psych::noPwd()
{
    string newPwd = newPassword();

    LockGuard lg{ d_lockPath, d_lockFd };

    string data;
    if (data = getData(); data.empty()) // getData calls Display on error
        return;

    d_record.pwdHash = Tools::md5hash(newPwd);

    data.replace(8, d_record.size, d_record.toString());
    d_psychData.update(nipKey(), data);

    getPrivate(data, 8 + d_record.size);

    Mailer mailer;
    mailer.sendmail(
                "frank@localhost", 
                "3ppq.nl wijziging",
                DollarText{ g_options.mail() + "nopwd", 
                    {
                        d_private.genderText(),     // $0
                        d_private.lastName,         // $1
                        newPwd                      // $2
                    }
                }.text() 
            );

    Display{ g_options.html() + "nopwd" };
}
