#include "tools.ih"

namespace
{

    mt19937 engine(time(0));
    uniform_int_distribution<> uid;
}

// static
size_t Tools::random(int max)           // return [0..max)
{
    if (max <= 1)
        return 0;

    uid.param(uniform_int_distribution<>::param_type{0, max - 1});
    return uid(engine);
}

