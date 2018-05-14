#include "lockguard.ih"

LockGuard::LockGuard(string const &path, int fd)
:
    d_fd(fd),
    d_path(path)
{
    if (d_fd == -1)
        return;

    if (s_locked.find(path) == s_locked.end())  // not yet locked
    {
        if (flock(d_fd, LOCK_EX) != 0)          // then lock the stream
        {
            g_log << "can't lock " << path << endl;
            throw Tools::NO_DATA;
        }
    }
    ++s_locked[path];
}













