#include "options.ih"

Options::Options()
{
    initialize(Arg::instance()[0]);

//    d_toMonitorFd = makeFifo(d_toMonitor);
//    d_fromMonitorFd = makeFifo(d_fromMonitor);
}
