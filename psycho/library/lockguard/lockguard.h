#ifndef INCLUDED_LOCKGUARD_
#define INCLUDED_LOCKGUARD_

#include "../lfstream/lfstream.h"

class LockGuard
{
    Lfstream *d_lfstream = 0;
    size_t d_lockCount = 0;

    public:
        LockGuard() = default;
        LockGuard(Lfstream &lfstream);
        ~LockGuard();

        void lock(Lfstream &lfstream);
    private:
        void lock();
};
        

#endif
