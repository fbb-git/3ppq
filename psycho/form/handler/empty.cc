#include "handler.ih"

void Handler::empty()       // called when the URI is unknown
{
    logParams();
    Display display(d_cgi);
    display.out("homepage.h");
}
