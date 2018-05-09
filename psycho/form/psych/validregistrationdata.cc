#include "psych.ih"

bool Psych::validRegistrationData(uint64_t *nip, uint8_t *field)
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
        throw false;

    *field = parseField();
}
