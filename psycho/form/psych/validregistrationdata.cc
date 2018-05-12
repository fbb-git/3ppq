#include "psych.ih"

bool Psych::validRegistrationData(uint64_t *nip, uint8_t *field)
try
{
g_log << "valideRegistrationData called" << endl;
    *nip = requireNumber("nip");
    requireOneOf("email", "@");
    requireContents("pwd");
    requireContents("name");
    requireContents("lastName");

g_log << "valideRegistrationData fields present" << endl;

    if 
    (
        string pwd = d_cgi->param1("pwd");
            pwd != d_cgi->param1("pwd2")            || 
            not pwdRequirements(pwd)                ||
            *nip == 0
    )
        return false;

    *field = parseField();
    return true;
}
catch (bool)
{
    g_log << "validRegistrationData failed" << endl;
    return false;
}

