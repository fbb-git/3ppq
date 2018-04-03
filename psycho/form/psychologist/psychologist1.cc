#include "psychologist.ih"

Psychologist::Psychologist(CGI &cgi)
:
    d_path(g_options.psychologists()),
    d_cgi(cgi),
    d_psychData(d_path),
    d_lockFd(creat((d_path + ".lck").c_str(), 0660))
{
    if (d_lockFd == -1)
        g_log << "can't use " << (d_path + ".lck") << endl;
}
