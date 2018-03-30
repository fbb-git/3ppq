#include "tools.ih"

int Tools::unlock(int fd)
{
    flock(fd, LOCK_UN);
    return -1;
}
