#include "psych.ih"

string Psych::messages()
try
{
    string path = g_options.moldsDir() + "messages";

    Stat stat{ path };

    if (not stat or stat.size() == 0)
        throw 0;

    ifstream in{ path };

    Exception::open(in, g_options.moldsDir() + "messages");

    ostringstream msg;

    msg << "<h1>Ter info...</h1>\n" 
            "<pre>\n" << in.rdbuf() << "\n"
            "</pre>\n";

    return msg.str();
}
catch (...)
{
    return "<h1>Er zijn geen berichten</h1>";
}
