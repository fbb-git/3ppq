#include "psychologist.ih"

Psychologist::Psychologist(CGI &cgi)
:
    d_path(g_options.psychologists()),
    d_lockPath(d_path + ".lck"),
    d_lockFd(creat(d_lockPath.c_str(), 0660)),
    d_psychData(d_path),
    d_cgi(cgi)
{
    if (d_lockFd == -1)
        g_log << "can't use " << d_lockPath << endl;
}
