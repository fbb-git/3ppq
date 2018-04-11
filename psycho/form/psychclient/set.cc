#include "psychclient.ih"

bool PsychClient::set(CGI &cgi)
{
    string gender = cgi.param1("gender");
    
    if (
        not Tools::checkParam(cgi, "name")        ||
        not Tools::checkParam(cgi, "lastName")    ||
        not Tools::checkParam(cgi, "email")       ||
        gender.empty() || 
        (gender.find_first_not_of("FM") != string::npos)
    )                     // invalid data
        return false;

    d_nr = ++s_nr;    

    d_name = cgi.param1("name");
    d_lastName = cgi.param1("lastName");
    d_email = cgi.param1("email");

    return true;
}


