#include "psych.ih"

bool Psych::acceptRegistration()
{
    string iv = Tools::iv();

    // uint16_t verification;

    if (
        not d_psychData.add(
               nipKey(), 
                iv + publicData() + Tools::encrypt(iv, privateData())
            )
    ) 
        return false;

    // TODO sendmail verification to email

    Display{ "acceptsignup" };

    return true;
}
