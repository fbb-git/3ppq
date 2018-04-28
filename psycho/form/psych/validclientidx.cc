#include "psych.ih"

uint16_t Psych::validClientIdx()
{
    uint16_t idx = Tools::valueOr(d_cgi.param1("clientIdx"), d_client.size());

    if (idx == d_client.size())
        throw false;

    return idx;
}
