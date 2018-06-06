#include "records.ih"

void Records::process()
{
    if (d_arg.option('l'))
        return list();

    if (d_arg.option('r'))
        return remove();

    if (d_arg.option('e'))
        return expired();

    if (d_arg.option('m'))
        return modify();

    d_arg.help();

}
