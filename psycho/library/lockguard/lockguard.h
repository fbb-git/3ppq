#ifndef INCLUDED_LOCKGUARD_
#define INCLUDED_LOCKGUARD_

#include "../lfstream/lfstream.h"

class LockGuard
{
    Lfstream &d_lfstream;

    public:
        LockGuard(Lfstream &lfstream);
        ~LockGuard();
};
        
#endif
