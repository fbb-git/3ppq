#include "formhandler.ih"

size_t FormHandler::getUid()
try
{
    return stoul(d_cgi.param1("uid"));
}
catch (...)
{
    return maxUint16;
}
