#include "tools.ih"

// static
long long Tools::valueOr(std::string const &value, int fallback)
try
{
    return stoll(value);
}
catch (...)
{
    return fallback;
}
