#include "tools.ih"

// static
string Tools::link(uint16_t psychID, uint16_t clientID, uint16_t loginValue)
{
    ostringstream out;

    out << g_config.findKeyTail("url:") << "/bin/form?" <<
            psychID << '.' << clientID << '=' << 
            md5hashText(to_string(loginValue));

    return out.str();
}
