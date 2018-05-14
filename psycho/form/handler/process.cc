#include "handler.ih"

void Handler::process()
try
{
    string const &type = d_cgi.param1("type");
 
    g_log << "Starting Handler::process: type = `" << type << '\'' << endl;

    if (type.empty())
        g_log << "No type. Query = `" << d_cgi.query() << '\'' << endl;
    else
        g_log << "state = `" << d_cgi.param1("state") << '\'' << endl;

    if (type == "psych")
        d_psych.process();

    else if (type == "client")
        d_client.process();

    else 
        d_client.accept(d_cgi.query());
}
catch (Tools::MessageEnum enumValue)
{
    g_log << "Caught enumValue " << enumValue << endl;

    logParams();

    DateTime now{ DateTime::LOCALTIME };

    Display display;
    display.out("error.h",
        {
            Tools::message(enumValue),
            now.rfc2822()            
        }
    );
}






