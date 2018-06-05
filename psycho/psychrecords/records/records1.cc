#include "records.ih"

Records::Records()
:
    d_arg(Arg::instance()),
    d_data(d_arg[0]),
    d_dataIdx(d_data + ".idx")
{}
