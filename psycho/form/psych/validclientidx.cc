#include "psych.ih"

size_t Psych::validClientIdx()
{
    return Tools::valueOr(d_cgi->param1("clientIdx"), d_client.size());
}


