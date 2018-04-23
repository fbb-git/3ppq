#include "psych.ih"

string Psych::clientLink(uint16_t clientID, uint16_t loginValue) const
{
    ostringstream out;

    out << g_config.findKeyTail("url:") << "/vragenlijst?" <<
            d_ID << '.' << clientID << '.' << 
            Tools::md5hashText(to_string(loginValue));

    return out.str();
}
