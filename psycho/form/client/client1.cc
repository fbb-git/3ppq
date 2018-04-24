#include "client.ih"

Client::Client(CGI &cgi)
:
    d_cgi(cgi),
    d_display(d_cgi)
{
//    ifstream questions;
//    Exception::open(questions, g_options.questions());
//
//    while (true)
//    {
//        string line;
//        if (not (questions >> line))    // skip the leading nr
//            break;
//        getline(questions, line);
//        d_lines.push_back(line);
//    }
}
