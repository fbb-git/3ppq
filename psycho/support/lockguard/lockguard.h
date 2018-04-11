#ifndef INCLUDED_LOCKGUARD_
#define INCLUDED_LOCKGUARD_

#include <iosfwd>

class LockGuard
{
    int d_fd;

    public:
        LockGuard(std::string const &path, int fd);
        ~LockGuard();
};
        

#endif
