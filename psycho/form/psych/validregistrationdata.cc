#include "psych.ih"

bool Psych::validRegistrationData(uint64_t *nip, uint8_t *field)
{
    *nip = Tools::valueOr(d_cgi.param1("nip"), 0);

    string email = d_cgi.param1("email");

    *field = parseField();

    string pwd = d_cgi.param1("pwd");

    return                                     // inspect data validity
        count(email.begin(), email.end(), '@') == 1 &&
        *nip != 0                                   &&
        *field != static_cast<uint8_t>(~0)          &&
        Tools::checkParam(d_cgi, "pwd")             &&
        pwd == d_cgi.param1("pwd2")                 &&
        pwd.length() >= Tools::MIN_PWD_LENGTH       && 
        Tools::checkParam(d_cgi, "name")            &&
        Tools::checkParam(d_cgi, "lastName")        &&
        Tools::checkParam(d_cgi, "email");
}
