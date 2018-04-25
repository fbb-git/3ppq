#ifndef INCLUDED_LOCKGUARD_
#define INCLUDED_LOCKGUARD_

#include <iosfwd>
#include <string>

class LockGuard
{
    int d_fd = -1;
    std::string d_path;
    size_t d_count = 0;

    public:
        LockGuard() = default;
        LockGuard(std::string const &path, int fd);
        ~LockGuard();
};
        

#endif
