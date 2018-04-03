#include "lockguard.ih"

LockGuard::LockGuard(std::string const &name, int fd)
:
    d_fd(fd)
{
    if (d_fd != -1 && flock(d_fd, LOCK_EX) != 0)
        g_log << "can't lock " << name << endl;

}












