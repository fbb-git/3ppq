#include "handler.ih"

void Handler::empty()       // called when the URI is unknown
{
    logParams();
    Display{ g_options.html() + "ack" };
}
