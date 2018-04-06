#include "psych.ih"

bool Psych::pwdMatch() const
{
    ostringstream out;

    for (int ch: d_record.pwdHash)
        out << ch << ' ';
        
    g_log << "stored hash length: " << d_record.pwdHash.length() << endl;
    g_log << "stored hash: " << out.str() << endl;

    string pwd = d_cgi.param1("pwd");
    g_log << "pwd = `" << pwd << '\'' << endl;
    
    pwd = Tools::md5hash(d_cgi.param1("pwd"));

    out.str("");
    for (int ch: pwd)
        out << ch << ' ';
        
    g_log << "hash length: " << pwd.length() << endl;
    g_log << "received hash: " << out.str() << endl;

    return d_record.pwdHash == Tools::md5hash(d_cgi.param1("pwd"));
}



