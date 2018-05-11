#ifndef INCLUDED_LOCKGUARD_
#define INCLUDED_LOCKGUARD_

#include <iosfwd>
#include <string>
#include <unordered_map>

class LockGuard
{
    int d_fd = -1;                  // fd of the .lck file
    std::string d_path;             // path of the file, not of the .lck file

    static std::unordered_map<std::string, size_t> s_locked;

    public:
        LockGuard() = default;
        LockGuard(std::string const &path, int fd);
        ~LockGuard();
};
        

#endif
