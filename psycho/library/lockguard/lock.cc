#include "lockguard.ih"

void LockGuard::lock(Lfstream &lfstream)
{
    if (d_lfstream != 0)
        throw Exception{} << "LockGuard: already configured";

    d_lfstream = &lfstream;

    lock();
}
