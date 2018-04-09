#include "tools.ih"

// static
void Tools::rename(std::string const &oldName, string const &newName)
{
    ::rename(oldName.c_str(), newName.c_str());

}
