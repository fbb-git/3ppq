#include "handler.ih"

size_t Handler::getUid()
try
{
    return stoul(d_cgi.param1("uid"));
}
catch (...)
{
    return maxUint16;
}
