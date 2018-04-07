#include "handler.ih"

void Handler::process()
{
    string const &type = d_cgi.param1("type");
 
    g_log << "Starting Handler::process: type = `" << type << '\'' << endl;
    g_log << "Starting Handler::process: state = `" << 
                                            d_cgi.param1("state") << '\'' << 
                                            endl;

    if (type == "psych")
        d_psych.process();

    else if (type == "client")
        d_client.process();

    else 
        empty();
}






