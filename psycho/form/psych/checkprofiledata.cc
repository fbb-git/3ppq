#include "psych.ih"

//    var name =        form["name"].value;
//    var lastName =    form["lastName"].value;
//    var nip =         form["nip"].value;
//    var email =       form["email"].value;
//    var newemail =    form["newemail"].value;
//    var pwd =         form["pwd"].value;
//    var newpwd =      form["newpwd"].value;
//    var newpwd2 =     form["newpwd2"].value;
//    var field =       form["field"].value;

bool Psych::checkProfileData(uint8_t *field)
{
    string newemail = d_cgi->param1("newemail");

    *field = parseField();

    string newpwd = d_cgi->param1("newpwd");

    return                                     // inspect data validity
        (d_nip = Tools::valueOr(d_cgi->param1("nip"), 0))    &&
        count(newemail.begin(), newemail.end(), '@') == 1   &&
        *field != static_cast<uint8_t>(~0)                  &&
        newpwd == d_cgi->param1("newpwd2")                   &&
        (                                                   
            newpwd.empty() ||                               
            newpwd.length() >= Tools::MIN_PWD_LENGTH        
        )                                                   && 
        Tools::checkParam(*d_cgi, "name")                    &&
        Tools::checkParam(*d_cgi, "lastName")                &&
        Tools::checkParam(*d_cgi, "newemail");
}


