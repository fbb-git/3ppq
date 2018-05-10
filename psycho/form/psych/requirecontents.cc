#include "psych.ih"

void Psych::requireContents(char const *name)
{
    if (Tools::checkParam(*d_cgi, name))
        return;

    g_log << "cgi param " << name << " `" << d_cgi->param1(name) << 
                                            "': no contents" << endl;
    throw false;
}
