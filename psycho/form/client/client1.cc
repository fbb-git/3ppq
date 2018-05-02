#include "client.ih"

Client::Client(CGI &cgi)
:
    d_cgi(cgi),
    d_display(d_cgi)
{}
