#include "options.ih"

Options::Options(std::string const &baseDir)
{
    initialize(baseDir);

//    d_toMonitorFd = fifoFd(d_toMonitor);
//    d_fromMonitorFd = fifoFd(d_fromMonitor);
}

