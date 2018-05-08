#include "psych.ih"

void Psych::report()
{
    LockGuard lg { d_data.lg() };

    if (not get())
        throw false;

    size_t clientIdx = stoul(d_cgi->param1("show"));

    if (clientIdx >= d_client.size())       // illegal client idx
        throw false;

    string path = g_options.reportsDir() + 
                to_string(d_ID) + '.' + d_client[clientIdx].ident() + ".pdf";

    Stat stat{ path };

    if (not stat)                           // no such report??
        throw false;

    ifstream in{ path };

    cout << "Content-type: application/pdf\r\n"
            "Content-length: " << stat.size() << "\r\n\r\n" <<
            in.rdbuf();
}




