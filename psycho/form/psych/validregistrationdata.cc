#include "psych.ih"

bool Psych::validRegistrationData(uint64_t *nip, uint8_t *field)
try
{
    *nip = requireNumber("nip");
    requireOneOf("email", "@");
    requireContents("pwd");
    requireContents("name");
    requireContents("lastName");

    if 
    (
        string pwd = d_cgi->param1("pwd");

        pwd != d_cgi->param1("pw2")             || 
        pwd.length() < Tools::MIN_PWD_LENGTH    ||
        *nip == 0
    )
        return false;

    *field = parseField();
    return true;
}
catch (bool)
{
    return false;
}

