#include "psych.ih"

bool Psych::pwdMatch() const
{
//    string pwd = d_cgi.param1("pwd");
//    g_log << "pwd = `" << pwd << '\'' << endl;
//    string pwd = Tools::md5hash(d_cgi.param1("pwd"));

    return d_pwdHash == Tools::md5hash(d_cgi.param1("pwd"));
}






