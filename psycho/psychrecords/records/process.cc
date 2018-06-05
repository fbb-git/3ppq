#include "records.ih"

void Records::process()
{
    if (d_arg.option('l'))
        return list();

    if (d_arg.option('r'))
        return remove();

//    if (d_arg.option('e'))
//        return expired(arg[0]);
//
//    if (d_arg.option(&newData, 'm'))
//        return modify(arg[0], newData);

    d_arg.help();

}
