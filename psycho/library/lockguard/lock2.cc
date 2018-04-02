#include "lockguard.ih"

void LockGuard::lock()
{
    d_lfstream->lock();
    ++d_lockCount;
}
