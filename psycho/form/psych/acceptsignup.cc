#include "psych.ih"

bool Psych::acceptSignup()
{
    d_nip = Tools::valueOr(d_cgi.param1("nip"), 0);

    string gender = d_cgi.param1("gender");
    
    if (
        (d_nip == 0) ||
        not Tools::checkParam(d_cgi, "pwd")         ||
        not Tools::checkParam(d_cgi, "name")        ||
        not Tools::checkParam(d_cgi, "lastName")    ||
        not Tools::checkParam(d_cgi, "email")       ||
        gender.empty() || 
        (gender.find_first_not_of("FM") != string::npos)
        
    )                     // invalid data
        return false;

    d_time = time(0);                       // then the data
    d_ack = Tools::random(1000, 9999);
    d_flags = 0;
    d_nr = ++s_nr;    
    d_pwdHash = Tools::md5hash(d_cgi.param1("pwd"));
    d_name = d_cgi.param1("name");
    d_lastName = d_cgi.param1("lastName");
    d_email = d_cgi.param1("email");

    if (not d_data.add(nipKey(), toString()))
        return false;

    Display{ g_options.html() + "acceptsignup" };

    return true;
}
