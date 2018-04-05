#include "psych.ih"

bool Psych::acceptSignup()
{
    string iv = Tools::iv();

    // uint16_t verification;

    if (
        not d_psychData.add(
               nipKey(), 
                iv + publicData() + Tools::encrypt(iv, privateData())
            )
    ) 
    {
        g_log << "acceptSignup fails" << endl;
        return false;
    }

    g_log << "acceptSignup OK" << '\n';
    // TODO sendmail verification to email

    Display{ "acceptsignup" };

    return true;
}