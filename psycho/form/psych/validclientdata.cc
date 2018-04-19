#include "psych.ih"

uint32_t Psych::validClientData()
{
    uint32_t active = d_cgi.param1("active") == "1" ? time(0) : 0;

    string clEmail = d_cgi.param1("clEmail");
    string gender = d_cgi.param1("gender");

    if (                                            // inspect data validity
        count(clEmail.begin(), clEmail.end(), '@') == 1 &&
        Tools::checkParam(d_cgi, "name")                &&
        Tools::checkParam(d_cgi, "lastName")            &&
        Tools::checkParam(d_cgi, "clEmail")             &&
        (gender == "M" || gender == "V")
    )
        return active;

    throw false;
}
