#include "options.ih"

int Options::makeFifo(string const &fifo)  
{
    unlink(fifo.c_str());  // rm any existing file by this name
    int fd;

    struct group *gptr = getgrnam("www-data");  // the webserver (i.e., CGI
                        // program) must be allowed to access the fifos

    umask(007);         // umask required to accept permission 0660 for 
                        // the fifos

    if (
        mkfifo(fifo.c_str(), 0660) != 0     
        ||
        (fd = open(fifo.c_str(), O_RDWR, 0660)) == -1
        ||
        chown(fifo.c_str(), getuid(), gptr->gr_gid) != 0 // gid: www-data
    )
        throw Exception{} << 
            "Can't open fifo " << fifo << ": " << errnodescr;

    return fd;
}
