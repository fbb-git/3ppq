#include "lockguard.ih"

LockGuard::LockGuard(Lfstream &lfstream)
:
    d_lfstream(&lfstream)
{
    lock();
}
