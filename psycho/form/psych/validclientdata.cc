#include "psych.ih"

uint32_t Psych::validClientData()
{
    uint32_t active = d_cgi.param1("active") == "1" ? time(0) : 0;

    string clEmail = d_cgi.param1("clEmail");
    string gender = d_cgi.param1("gender");
    if (gender.empty())
        gender = d_cgi.param1("xgender");

g_log << "valid client data: active: " << active << 
            ", email: " <<  clEmail << 
            ", ID: " << d_cgi.param1("ID") << 
            ", gender: " << gender << 
            ", name: " << d_cgi.param1("name") << 
            ", lastname: " << d_cgi.param1("lastName") << endl;


    if (                                            // inspect data validity
        count(clEmail.begin(), clEmail.end(), '@') == 1 &&
        Tools::checkParam(d_cgi, "name")                &&
        Tools::checkParam(d_cgi, "lastName")            &&
        Tools::checkParam(d_cgi, "clEmail")             &&
        (gender == "M" || gender == "V")
    )
        return active;

g_log << "valid data fails " << endl;

    return active;

    throw false;
}

