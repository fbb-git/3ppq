#include "lockguard.ih"

LockGuard::LockGuard(string const &path, int fd)
:
    d_fd(fd),
    d_path(path)
{
    if (d_fd != -1 && flock(d_fd, LOCK_EX) != 0)
        throw Exception{} << "can't lock " << path;

    ++d_count;
}













