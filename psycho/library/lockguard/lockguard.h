#ifndef INCLUDED_LOCKGUARD_
#define INCLUDED_LOCKGUARD_

#include <iosfwd>

class LockGuard
{
    int d_fd;

    public:
        LockGuard(std::string const &name, int fd);
        ~LockGuard();
};
        

#endif
