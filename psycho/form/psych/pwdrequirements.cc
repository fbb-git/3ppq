#include "psych.ih"

namespace {

    Pattern hasDigit{ "\\d" };
    Pattern hasLetter{ "[[:alpha:]]" };
    Pattern hasSpecial{ R"R([-.,\\/#!$%^&*;:{}=`~()])R" };
}

// static
bool Psych::pwdRequirements(string const &pwd)
try
{
    g_log << "pwdRequirements" << endl;

    hasDigit.match(pwd);
    hasLetter.match(pwd);
    hasSpecial.match(pwd);

    return pwd.length() >= Tools::MIN_PWD_LENGTH;        
}
catch (exception const &exc)
{
    g_log << exc.what() << endl;
    return false;
}
catch (...)
{
    return false;
}

    
