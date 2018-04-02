#include "lockguard.ih"

LockGuard::~LockGuard()
{
    if (d_lfstream && d_lockCount)
    {
        if (--d_lockCount == 0)
            d_lfstream->unlock();
    }
}
