#include "lockguard.ih"

LockGuard::~LockGuard()
{
    if (d_count)
        --d_count;

    if (d_fd != -1 and d_count == 0)
        flock(d_fd, LOCK_UN);
}
