#include "lockguard.ih"

LockGuard::~LockGuard()
{
    d_lfstream.unlock();
}
