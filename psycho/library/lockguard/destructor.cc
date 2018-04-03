#include "lockguard.ih"

LockGuard::~LockGuard()
{
    flock(d_fd, LOCK_UN);
}
