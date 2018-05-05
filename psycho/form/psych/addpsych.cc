#include "psych.ih"

//    var name =      form["name"].value;
//    var lastName =  form["lastName"].value;
//    var email =     form["email"].value;
//    var pwd =       form["pwd"].value;
//    var pwd2 =      form["pwd2"].value;
//    var field =     form["field"].value;

void Psych::addPsych()
{
    if (not validRegistrationData(&d_nip, &d_field))
    {
        d_display.out("rejectpsych.h");
        return;
    }

    string pwd{ d_cgi.param1("pwd") };

    d_time      = time(0);                      // assign remaining fields
    d_ack       = Tools::random(1000, 9999);
    d_nClients  = 0;
    d_ID        = d_data.nextNr();
    d_pwdHash   = Tools::md5hash(pwd);
    d_name      = d_cgi.param1("name");
    d_lastName  = d_cgi.param1("lastName");
    d_email     = d_cgi.param1("email");

    LockGuard lg{ d_data.lg() };

    resultsDir(pwd);

    d_display.out(
        d_data.add(emailKey(), toString()) ? "ackcheck.h" : "knownpsych.h"
    );
}







