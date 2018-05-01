#include "tools.ih"

// static 
string Tools::link(uint16_t psychID, string const &clientIdent,
                   uint16_t loginValue) 
{
    ostringstream out;

    out << g_config.findKeyTail("url:") << "/bin/form?" <<
            psychID << '.' << clientIdent << '=' << 
            md5hashText(to_string(loginValue));

    return out.str();
}
