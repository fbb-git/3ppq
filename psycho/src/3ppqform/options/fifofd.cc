#include "options.ih"

int Options::fifoFd(string const &fifo)  
{
    int fd;

    if ((fd = open(fifo.c_str(), O_RDWR, 0600)) == -1)
        throw Exception{} << 
            "Can't open fifo " << fifo << ": " << errnodescr;

    return fd;
}
