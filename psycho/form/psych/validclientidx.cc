#include "psych.ih"

size_t Psych::validClientIdx()
{
    size_t idx = Tools::valueOr(d_cgi->param1("clientIdx"), d_client.size());

    if (idx < d_client.size())
        return idx;

    throw Tools::NO_CLIENT;
}


