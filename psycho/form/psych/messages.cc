#include "psych.ih"

string Psych::messages()
{
    string path = g_options.moldsDir() + "messages";

    if (not Tools::rwExists(path))
        return "<h1>Er zijn geen berichten</h1>";

    ifstream in{ path };

    ostringstream msg;

    msg << "<h1>Ter info...</h1>\n" 
            "<pre>\n" << in.rdbuf() << "\n"
            "</pre>\n";

    return msg.str();
}
